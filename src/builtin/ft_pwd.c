/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 03:30:30 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 18:10:08 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#include "util.h"
#include "built_in.h"

static int	check_option(char *str)
{
	if (_strcmp(str, "--") && str[0] == '-' && _strlen(str) > 1)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_pwd(t_exec *data, int pipe_flag)
{
	char	*now_path;
	char	**argv;

	argv = data->cmd_argv;
	argv++;
	if (*argv && check_option(*argv))
	{
		_putendl_fd("option T.T", 2);
		return ;
	}
	now_path = NULL;
	now_path = getcwd(NULL, 256);
	if (now_path == NULL)
	{
		_putendl_fd("fail getcwd()", 2);
		exit(1);
	}
	_putendl_fd(now_path, 1);
	g_minishell.exit_status = 0;
	free(now_path);
	if (pipe_flag)
		exit(0);
}
