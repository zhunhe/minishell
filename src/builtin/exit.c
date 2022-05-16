#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includehena/test.h"
#include "../includehena/built_in.h"
#include <string.h>
/*
*	exit 1 2 3 exit: too many arguments exit 출력
*	exit 1 a b exit: too many arguments exit 출력
*	exit a b c : numeric argument required
*/

t_minishell g_minishell;

static void	ft_exit_execute(char **argv, int pipe_flag)
{
	int	ret;
	// 숫자라면
	if (check_all_integer(*argv))
	{
		if (!pipe_flag)
			write(1, "exit\n", 5);
		ret = ft_atoi(*argv);
		argv++;
		if (*argv)
			print_exit_error("", 0);
		// 번호 담아줘야할듯
	}
	else
	{
		print_exit_error(*argv, 1);
		// 번호 담아줘야할듯
	}
	exit(0);
}

void	ft_exit(t_exec *data, int pipe_flag)
{
	char	**argv;
/*	COMPILE ERROR
	int	i;
*/

	argv = data->argv;
	argv++;
	if (*argv == NULL)
	{
		if (!pipe_flag)
			write(1, "exit\n", 5);
		exit(0);
	}
	else
		ft_exit_execute(argv, pipe_flag);
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
	data->cmd = strdup("exit");
	data->cmd_address = strdup("/bin/exit");
	data->argv = (char **)malloc(sizeof(char *) * 4);
	data->argv[0] = strdup("exit");
	data->argv[1] = NULL;
	ft_exit(data, 0);
}
#endif