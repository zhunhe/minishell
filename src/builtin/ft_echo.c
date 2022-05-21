/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:35:46 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 18:10:08 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "parse.h"
#include "util.h"
#define TRUE 1
#define FALSE 0

static int	check_option(char *str, int *opt)
{
	int	i;

	if (!(str[0] == '-' && str[1] == 'n'))
		return (FALSE);
	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (FALSE);
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
			_putstr_fd(*argv, 1);
		else
		{
			_putstr_fd(*argv, 1);
			_putstr_fd(" ", 1);
		}
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
			break ;
		argv++;
	}
	print_echo(argv);
	if (!opt_flag)
		_putendl_fd("", 1);
	g_minishell.exit_status = 0;
	if (pipe_flag)
		exit(0);
}
