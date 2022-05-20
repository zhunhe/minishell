/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:30:56 by hena              #+#    #+#             */
/*   Updated: 2022/05/19 00:30:59 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#include "built_in.h"
#include "util.h"

int	check_option(char *str)
{
	if (!_strncmp(str, "-", 1) && _strlen(str) > 1 && _strcmp(str, "--"))
	{
		g_minishell.state = 1;
		_putendl_fd("option T.T", 2);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_cd(t_exec *data, int pipe_flag)
{
	char	**argv;
	char	*now;

	g_minishell.state = 0;
	now = getcwd(NULL, 256);
	argv = data->cmd_argv;
	argv++;
	if (go_home_dir(*argv, now))
		;
	else if (check_option(*argv))
		;
	else if (!_strcmp(*argv, "-"))
		change_to_old_path(now);
	else if (!_strcmp(*argv, "~") || !_strncmp(*argv, "~/", 2))
		use_tilde(*argv, now);
	else if (!chdir(*argv))
		change_values(now);
	else
		print_error_cd(*argv);
	free(now);
	if (pipe_flag)
		exit(g_minishell.state);
}
