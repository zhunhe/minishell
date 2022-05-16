#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#include "check_string_util.h"

# define TRUE 1
# define FALSE 0

extern t_minishell g_minishell;

static void	ft_print_export(char *key, char *value)
{
	write(1, "declare -x ", 11);
	write(1, key, strlen(key));
	if (value)
	{
		write(1, "=\"", 2);
		write(1, value, strlen(value));
		write(1, "\"\n", 2);
	}
}


static void	show_export_list(int pipe_flag)
{
	t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		ft_print_export(envp->key, envp->value);
		envpl = envpl->next;
	}
	g_minishell.state = 0;
	if (pipe_flag)
		exit(0);
}



static int	is_valid_idenfier(char *str)
{
	if (!((is_small_alpha(*str) || is_big_alpha(*str) || *str == '_')))
		return (FALSE);
	while (*str)
	{
		if (!((is_small_alpha(*str) || is_big_alpha(*str) || \
		is_digit(*str) || *str == '_')))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	get_equal_index(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			flag = 1;
			break ;
		}
		++i;
	}
	if (!flag)
		return (-1);
	return (i);
}

void	set_key_value(char *str, char **key, char **value, int index)
{
	int i;
	int j;
	int len;

	i = -1;
	j = -1;
	len = strlen(str);
	if (index == -1) // = (x)
	{
		*key = (char *)malloc(sizeof(char) * len + 1);
		while(++i < (int)strlen(str))
			(*key)[i] = str[i];
	}
	else
	{
		*key = (char *)malloc(sizeof(char) * index + 1);
		while(++i < index)// =제외
			(*key)[i] = str[i];
		*value = (char *)malloc(sizeof(char) * len - 1);
		++i;
		while(++j < (int)strlen(str))
			(*value)[j] = str[i + j];
	}
}

void	find_or_change_envp(char *key, char *value)
{
	t_list	*envpl;
	t_list	*last;
	t_envp	*envp;
	int		exist_flag;

	exist_flag = 0;
	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!strcmp(envp->key, key))
		{
			free(envp->value);
			envp->value = strdup(value);
			exist_flag = 1;
			break;
		}
		envpl = envpl->next;
	}
	
	last = g_minishell.envp;
	while (last->next)
		last = last->next;

	if (!exist_flag)
	{
		envpl = (t_list	*)malloc(sizeof(t_list));
		envp = (t_envp *)malloc(sizeof(t_envp));
		envp->key = key;
		envp->value = value;
		envpl->data = envp;
		last = envpl;
	}
}

int	divide_argv(char **argv)
{
	int err_flag;
	int index;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	err_flag = 0;
	while (*argv)
	{
		index = get_equal_index(*argv);
		set_key_value(*argv, &key, &value, index);
		if (!is_valid_idenfier(key))
		{
			free(key);
			write(2, "export: `", 9);
			write(2, *argv, strlen(*argv));
			write(2, "': not a valid identifier\n", 26);
			err_flag = 1;
		}
		else
			find_or_change_envp(key, value);
		argv++;
	}
	return (err_flag);
}

void	export(t_exec *data, int pipe_flag)
{
	char	**argv;
	int		ret;

	ret = 0;
	argv = data->cmd_argv;
	argv++;
	if (!*argv)
		show_export_list(pipe_flag);
	else						//TODO:: 다시 만들어야 할 듯.
		divide_argv(argv);
}
