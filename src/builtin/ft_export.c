/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:52:03 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 18:52:04 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <util.h>
#include "minishell.h"
#include "parse.h"
#include "built_in.h"

void	ft_print_export_error(char *argv)
{
	_putstr_fd("export: `", 2);
	_putstr_fd(argv, 2);
	_putendl_fd("': not a valid identifier", 2);
}

static void	ft_print_export(char *key, char *value)
{
	_putstr_fd("declare -x ", 1);
	_putstr_fd(key, 1);
	if (value)
	{
		_putstr_fd("=\"", 1);
		_putstr_fd(value, 1);
		_putendl_fd("\"", 1);
	}
	else
		_putendl_fd("", 1);
}

static void	show_export_list(int pipe_flag)
{
	t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		ft_print_export(envp->key, envp->value);
		envpl = envpl->next;
	}
	g_minishell.state = 0;
	if (pipe_flag)
		exit(0);
}

void	ft_export(t_exec *data, int pipe_flag)
{
	char	**argv;
	int		ret;

	ret = 0;
	argv = data->cmd_argv;
	argv++;
	if (!*argv)
		show_export_list(pipe_flag);
	else
		ret = divide_argv(argv);
	g_minishell.state = ret;
	if (pipe_flag)
		exit(ret);
}
