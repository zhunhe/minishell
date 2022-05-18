#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#include "built_in.h"

#define TRUE 1
#define FALSE 0

// extern t_minishell g_minishell;
t_minishell g_minishell;

int	check_option(char *str)
{
	if (!strncmp(str, "-P", 2) || !strncmp(str, "-L", 2)) //TODO:: 함수 만들어서 바꿔야 함
		return (TRUE);
	return (FALSE);
}

char	*find_home_path(int *flag)
{
	t_list	*envpl;
	t_envp	*envp;
	char 	*path;

	*flag = 0;
	path = NULL;
	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!strcmp(envp->key, "HOME")) // TODO::
		{
			path = envp->value;
			*flag = 1;
			break ;
		}
		envpl = envpl->next;
	}
	return (path);
}

void	using_environment_value(char *now)
{
	int flag;
	char	*path;

	path = find_home_path(&flag);
	if (!flag)
	{
		write(2, "bash: cd: HOME not set\n", 23);
		return ;
	}
	if (path == NULL || !strcmp(path, ""))
		chdir(path);
	else
	{
		if (chdir(path) == -1)
		{
			write(2, "bash: cd: ", 10);
			write(2, path, strlen(path));
			write(2, ": No such file or directory\n", 28);
		}
		else
			change_values(now);
	}
}

void	non_using_environment_value(char *now)
{
	chdir("/Users/hena");	//TODO:: juhur로 바꿔야 함. 제껀에선 hena가 맞음.
	change_values(now);
}	//바꿔야할 듯

int home_check(char *argv, char *now)
{
	if (!argv)
	{
		using_environment_value(now);
		return (TRUE);
	}
	else if (!strcmp("~", argv)) // TODO:: ft_strcmp
	{
		non_using_environment_value(now);
		return (TRUE);
	}
	return (FALSE);
}


void	ft_cd(t_exec *data, int pipe_flag)
{
	int state;
	char	**argv;
	char	*now; 

	now = getcwd(NULL, 256);
	argv = data->cmd_argv;
	argv++;
	if (home_check(*argv, now))	
	{
		free(now);
		return ;
	}
	if (check_option(*argv))
	{
		write(2, "option T.T\n", 11);
		exit(1);
	}
	if (!strcmp(*argv, "-")) // TODO:: strcmp
	{
		change_to_old_path(now);
		free(now);
		return ;
	}
	state = chdir(*argv);
	// COMPILE ERROR
	if (state == -1 && *argv != NULL)
	{
		write(2, "bash: cd: ", 10);
		write(2, *argv, strlen(*argv));
		write(2, ": No such file or directory\n", 28);
		exit(1); // pipe플레그랑 같이 봐야할 듯
	}
	free(now);
	if (pipe_flag)
		exit(0);
}

#if 0
t_list *create_l()
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = 0;
	new->next = 0;
	return (new);
}

t_envp *create_e(char *key, char *value)
{
	t_envp	*new;

	new = (t_envp *)malloc(sizeof(t_envp));
	if (key)
		new->key = strdup(key);
	else
		new->key = NULL;
	if (value)
		new->value = strdup(value);
	else
		new->value = NULL;
	return (new);
}
#include <stdio.h>
int	main(void)
{
	g_minishell.envp = NULL;
	g_minishell.oldpwd = NULL;
	t_list	*envpl;
	t_envp	*envp;
	t_exec	*data;
	envpl = create_l();
	envp = create_e("HOME", "/Users/hena");
	g_minishell.envp = envpl;
	envpl->data = (void *)envp;

	envpl = create_l();
	envp = create_e("b", "test");
	g_minishell.envp->next = envpl;
	envpl->data = envp;

	envpl = create_l();
	envp = create_e("d", "hi");
	g_minishell.envp->next->next = envpl;
	envpl->data = envp;

	data = (t_exec*)malloc(sizeof(t_exec));
	data->cmd = strdup("cd");
	data->cmd_path = strdup("/bin/cd");
	data->cmd_argv = (char **)malloc(sizeof(char *) * 7);
	data->cmd_argv[0] = strdup("cd");
	data->cmd_argv[1] = strdup("~");
	data->cmd_argv[2] = NULL;
	// data->cmd_argv[3] =strdup("f=1");
	data->cmd_argv[3] = NULL;
	// data->cmd_argv[1] =strdup("1=a");
	// printf("%s\n", getcwd(NULL, 256));
	ft_cd(data, 0); 
	printf("%s\n", getcwd(NULL, 256));
	// printf("%s\n", g_minishell.oldpwd);
	
	// data->cmd_argv[4] =strdup("b=2");
	// data->cmd_argv[5] =strdup("c=3");
	// data->cmd_argv[6] = NULL;
	
	// data->cmd_argv[1] = NULL;
	// ft_cd(data, 0);
	while (1)
		;
}
#endif