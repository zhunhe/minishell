#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../includehena/test.h"
#include "../includehena/built_in.h"

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
	envpl = g_minishell.envp;// header있는지 써주면 ㄱㅅ
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
	if (!strcmp("~", argv)) // TODO:: ft_strcmp
	{
		non_using_environment_value(now);
		return (TRUE);
	}
	return (FALSE);
}


void	ft_cd(t_exec *data, int pipe_flag)
{
	int state;
/*	COMPILE ERROR
	char *prev;
*/
	char **argv;
	char	*now; 

	now = getcwd(NULL, 256);
	argv = data->argv;
	argv++;
	if (home_check(*argv, now))	
		return ;
	if (check_option(*argv))
		exit(1);
	if (!strcmp(*argv, "-")) // TODO:: strcmp
	{
		change_to_old_path(now);
		return ;
	}
	state = chdir(*argv);
/*	COMPILE ERROR
	if (state == -1 && *argv != "")
	{
		write(2, "bash: cd: ", 10);
		write(2, *argv, strlen(*argv));
		write(2, ": No such file or directory\n", 28);
		exit(1); // pipe플레그랑 같이 봐야할 듯
	}
*/
	if (pipe_flag)
		exit(0);
}

#if 0 // test용도 코드
t_exec *init_exec()
{
	t_exec *cmd;
	
	cmd = (t_exec *)malloc(sizeof(t_exec));
	cmd->cmd = NULL;
	cmd->cmd_address = NULL;
	cmd->fd = 0;
	cmd->pid = 0;
	return cmd;
}

int main(int argc, char **argv, char **envp)
{
	t_exec *data;

	data = init_exec();
	data->cmd = strdup("cd");
	data->cmd_address = strdup("/bin/cd");
	data->argv = (char **)malloc(sizeof(char *) * 4);
	data->argv[0] = strdup("cd");
	data->argv[1] = strdup("~");
	data->argv[2] = NULL;
	ft_cd(data, 0);
	
}
#endif