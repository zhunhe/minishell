/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:44:14 by hena              #+#    #+#             */
/*   Updated: 2022/05/22 13:17:02 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "minishell.h"
#include "parse.h"
#include "util.h"
#include "built_in.h"

void	free_list(t_list	*list)
{
	t_envp	*envp;

	envp = list->data;
	free(envp->key);
	free(envp->value);
	envp->key = NULL;
	envp->value = NULL;
	free(envp);
	envp = NULL;
	free(list);
	list = NULL;
}

static void	travel_list(t_list	*envpl, char *str)
{
	t_list	*prev;
	t_envp	*envp;

	prev = envpl;
	envpl = envpl->next;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!_strcmp(envp->key, str))
		{
			prev->next = envpl->next;
			free_list(envpl);
			break ;
		}
		envpl = envpl->next;
		prev = prev->next;
	}
}

static void	find_and_erase_key(char *str)
{
	t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp;
	if (!envpl)
		return ;
	envp = (t_envp *)envpl->data;
	if (!_strcmp(envp->key, str))
	{
		g_minishell.envp = envpl->next;
		free_list(envpl);
		return ;
	}
	travel_list(envpl, str);
}

static int	is_valid_idenfier(char *str)
{
	if (!(_isalpha(*str) || *str == '_'))
		return (FALSE);
	str++;
	while (*str)
	{
		if (!(_isalnum(*str) || *str == '_'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

void	ft_unset(t_exec	*data, int pipe_flag)
{
	char	**argv;

	argv = data->cmd_argv;
	argv++;
	g_minishell.exit_status = 0;
	while (*argv)
	{
		if (!is_valid_idenfier(*argv))
		{
			_putstr_fd("unset: `", 2);
			_putstr_fd(*argv, 2);
			_putendl_fd("': not a valid identifier", 2);
			g_minishell.exit_status = 1;
		}
		else
			find_and_erase_key(*argv);
		argv++;
	}
	if (pipe_flag)
		exit(g_minishell.exit_status);
}
