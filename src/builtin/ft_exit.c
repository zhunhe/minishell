/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:43:49 by hena              #+#    #+#             */
/*   Updated: 2022/05/22 12:56:59 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "minishell.h"
#include "parse.h"
#include "built_in.h"
#include "util.h"

static void	ft_exit_execute(char **argv, int pipe_flag)
{
	int	ret;

	if (check_all_integer(*argv))
	{
		ret = ft_atoi(*argv);
		if (!pipe_flag)
			_putendl_fd("exit", 1);
		argv++;
		if (*argv)
			print_exit_error("", 0, pipe_flag);
		else
			exit(ret);
	}
	else
		print_exit_error(*argv, 1, pipe_flag);
}

void	ft_exit(t_exec *data, int pipe_flag)
{
	char	**argv;

	argv = data->cmd_argv;
	argv++;
	if (*argv == NULL)
	{
		if (!pipe_flag)
			_putendl_fd("exit", 1);
		exit(0);
	}
	else
		ft_exit_execute(argv, pipe_flag);
}
