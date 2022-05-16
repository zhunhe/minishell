#include <stdio.h> // test
#include <stdlib.h>
#include <string.h>
#include "../includehena/test.h"
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
	{
		return (FALSE);
	}
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

void	ft_echo(t_exec *data, int pipe_flag)
{
	int		check_flag;
	int		opt_flag;
	char	**argv;

	argv = data->argv;
	// init
	init_valuable(&check_flag, &opt_flag);
	// echo 건너뛰기
	argv++;
	// 옵션인거 싹다 무시
	while (*argv && !check_flag)
	{
		if (!check_option(*argv, &opt_flag))
			break ;
		argv++;
	}
	while (*argv)
	{
		printf("%s", *argv);
		argv++;
	}
	if (!opt_flag)
		printf("\n");
	if (pipe_flag)
		exit(0);
}
