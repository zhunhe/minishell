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

#define TRUE 1
#define FALSE 0

int	check_option(char *str)
{
	if (!_strncmp(str, "-", 1) && _strlen(str) > 1 && _strcmp(str, "--"))
	{
		return (TRUE);
	}
	return (FALSE);
}

void	ft_cd(t_exec *data, int pipe_flag)
{
	char	**argv;
	char	*now;

	now = getcwd(NULL, 256);
	argv = data->cmd_argv;
	argv++;
	if (go_home_dir(*argv, now))
		free(now);
	else if (check_option(*argv))
		free(now);
	else if (!_strcmp(*argv, "-"))
	{
		change_to_old_path(now);
		free(now);
		return ;
	}
	if (chdir(*argv) == -1 && *argv != NULL)
	{
		print_error_cd(*argv);
		exit(1);
	}
	if (pipe_flag)
		exit(0);
}
