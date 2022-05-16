/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "parse.h"
#include "../includehena/built_in.h"
#include <string.h>

// *	exit 1 2 3 exit: too many arguments exit 출력
// *	exit 1 a b exit: too many arguments exit 출력
// *	exit a b c : numeric argument required


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

	argv = data->cmd_argv;
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
*/