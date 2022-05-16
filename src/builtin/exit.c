#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "minishell.h"
#include "parse.h"
#include "built_in.h"

// *	exit 1 2 3 exit: too many arguments exit 출력
// *	exit 1 a b exit: too many arguments exit 출력
// *	exit a b c : numeric argument required

t_minishell g_minishell;

static void	ft_exit_execute(char **argv, int pipe_flag)
{
	int	ret;

	if (check_all_integer(*argv))
	{
		if (!pipe_flag)
			write(1, "exit\n", 5);
		ret = ft_atoi(*argv);
		argv++;
		if (*argv)
			print_exit_error("", 0, pipe_flag);
	}
	else
	{
		print_exit_error(*argv, 1, pipe_flag);
	}
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

#if 0
// 확인 완료---------------- strlen이나 ft_putendl_fd만 처리
int	main(void)
{
	t_exec	*data;

	data = (t_exec *)malloc(sizeof(t_exec));
	data->cmd = strdup("exit");
	data->cmd_path = strdup("/bin/exit");
	data->cmd_argv = (char **)malloc(sizeof(char *) * 4);
	data->cmd_argv[0] = strdup("exit");
	data->cmd_argv[1] = strdup("asadasd");
	data->cmd_argv[2] = strdup("a");
	data->cmd_argv[3] = NULL;
	ft_exit(data, 0);
	while(1);
}
#endif