/*
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"
#include "parse.h"
#ifndef BOOL
# define BOOL

# define TRUE 1
# define FALSE 0
#endif

extern t_minishell g_minishell;

// // COMPILE ERROR
// static void	ft_print_export(char *key, char *value)
// {
// 	write(1, "declare -x ", 11);
// #if 0	// COMPILE ERROR
// 	write(1, key, ft_strlen(key));
// #endif
// 	if (value)
// 	{
// 		write(1, "=\"", 2);
// #if 0	// COMPILE ERROR
// 		write(1, value, ft_strlen(value));
// #endif
// 		write(1, "\"\n", 2);
// 	}
// }


static void	show_export_list(void)
{
#if 0	// COMPILE ERROR
	int	i;
#endif
	t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp->next;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
#if 0	// COMPILE ERROR
		ft_print_env(envp->key, envp->value);
#endif
		envpl++;
	}
	g_minishell.state = 0;
}

#if 0	// COMPILE ERROR
int	is_in_equal(char *str)
{
	while (*str)
		if (*str == '=')
			return (TRUE);
	return (FALSE);
}
#endif

void	find_or_change_envp(char *str)
{
	t_list	*envpl;
	t_envp	*envp;
	int	flag;
#if 0
	char **array;
#endif

	envpl = g_minishell.envp->next;
	flag = 0;
	if (!*str)
		return ;
	//1. = 유무
#if 0	// COMPILE ERROR
	flag = is_in_equal(*str);
#endif
#if 0	// COMPILE ERROR
	array = split(str, '=');
#endif
	// if (flag)
	// 	add_key();
	// else
	// 	add_key_value();
	//2. split
	flag = 0;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		// split 기준으로
#if 0	// COMPILE ERROR
		if (!ft_strcmp(envp->key, array[0]))
		{
			flag = 1;
#if 0	// COMPILE ERROR
			if ()
			{

			}
#endif
		}
#endif
		envpl++;
	}
}

static int	is_valid_idenfier(char *str, int index)
{
	int i;

#if 0	// COMPILE ERROR
	if (!((is_small_alpha(*str) || is_big_alpha(*str) || *str == '_')))
		return (FALSE);
#endif
	i = 1;
	while (*str && i < index)
	{
#if 0	// COMPILE ERROR
		if (!((is_small_alpha(*str) || is_big_alpha(*str) || \
		is_integer(*str) || *str == '_')))
			return (FALSE);
#endif
		str++;
		++i;
	}
	return (TRUE);
}

int	get_equal_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		++i;
	}
#if 0	// COMPILE ERROR
	if (ft_strlen(str) == i)
		return (-1);
#endif
	return (i);
}

int	divide_argv(char **argv)
{
	int err_flag;
	int index;

	err_flag = 0;
	while (*argv)
	{
		index = get_equal_index(*argv);
		// = 전까지만 확인해야함.... split이 먼저
		if (!is_valid_idenfier(*argv, index))
		{
			write(2, "export: `", 9);
#if 0	// COMPILE ERROR
			write(2, *argv, ft_strlen(*argv));
#endif
			write(2, "': not a valid identifier\n", 26);
			err_flag = 1;
		}
		else
			find_or_change_envp(*argv);
		argv++;
	}
	return (err_flag);
}

void	export(t_exec *data)
{
	char	**argv;

	argv = data->argv;
	argv++;
	if (!*argv)
		show_export_list();
	// else						TODO:: 다시 만들어야 할 듯.
	// 	divide_argv(argv);
}
*/