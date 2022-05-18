/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:50:36 by hena              #+#    #+#             */
/*   Updated: 2022/05/18 18:50:48 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#include "util.h"

extern t_minishell	g_minishell;

static void	ft_print_env(char *key, char *value)
{
	_putstr_fd(key, 1);
	write(1, "=", 1);
	_putstr_fd(value, 1);
	write(1, "\n", 1);
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
		exit(1);
	}
	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (envp->value)
			ft_print_env(envp->key, envp->value);
		envpl = envpl->next;
	}
	g_minishell.state = 0;
	if (pipe_flag)
		exit(0);
}
