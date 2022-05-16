#include <stdio.h> // test
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "parse.h"
// strcmp함수 만들어야 함
#ifndef BOOL
#define BOOL
#define TRUE 1
#define FALSE 0
#endif

static int	check_option(char *str, int *opt)
{
	int	i;

	if (!(str[0] == '-' && str[1] == 'n'))
		return (FALSE);
	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
		{
			return (FALSE);
		}
		++i;
	}
	*opt = 1;
	return (TRUE);
}	

static void	init_valuable(int *c_flag, int *o_flag)
{
	*c_flag = 0;
	*o_flag = 0;
}

static void	print_echo(char **argv)
{
	while (*argv)
	{
		if (!(*(argv + 1)))
			printf("%s", *argv);
		else
			printf("%s ", *argv);
		argv++;
	}
}

void	ft_echo(t_exec *data, int pipe_flag)
{
	int		check_flag;
	int		opt_flag;
	char	**argv;

	argv = data->cmd_argv;
	init_valuable(&check_flag, &opt_flag);
	argv++;
	while (*argv)
	{
		check_flag = check_option(*argv, &opt_flag);
		if (!check_flag)
			break;
		argv++;
	}
	print_echo(argv);
	if (!opt_flag)
		printf("\n");
	if (pipe_flag)
		exit(0);
}

#if 0
// 확인 완료---------------- strlen이나 ft_putendl_fd만 처리
int	main(void)
{
	t_exec	*data;

	data = (t_exec *)malloc(sizeof(t_exec));
	data->cmd = strdup("echo");
	data->cmd_path = strdup("/bin/echo");
	data->cmd_argv = (char **)malloc(sizeof(char *) * 5);
	data->cmd_argv[0] = strdup("echo");
	// data->cmd_argv[1] = strdup("-na");
	// data->cmd_argv[2] = strdup("-ns");
	// data->cmd_argv[3] = strdup("-na");
	data->cmd_argv[1] = NULL;
	// data->cmd_argv[3] = strdup("-");
	
	ft_echo(data, 0);
}
#endif