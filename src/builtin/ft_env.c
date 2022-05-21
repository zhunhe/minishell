/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:50:36 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 18:10:08 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#include "util.h"

static void	ft_print_env(char *key, char *value)
{
	_putstr_fd(key, 1);
	_putstr_fd("=", 1);
	_putstr_fd(value, 1);
	_putendl_fd("", 1);
}

void	ft_env(t_exec *data, int pipe_flag)
{
	t_list	*envpl;
	t_envp	*envp;
	char	**argv;

	argv = data->cmd_argv;
	argv++;
	if (*argv)
	{
		_putendl_fd("env must be one argv", 2);
		return ;
	}
	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (envp->value)
			ft_print_env(envp->key, envp->value);
		envpl = envpl->next;
	}
	g_minishell.exit_status = 0;
	if (pipe_flag)
		exit(0);
}
