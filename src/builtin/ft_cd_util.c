/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:27:51 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 18:27:59 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "parse.h"
#include "util.h"
#include "built_in.h"

void	change_global_oldpwd(char *prev)
{
	if (!g_minishell.oldpwd)
		g_minishell.oldpwd = _strdup(prev);
	else
	{
		free(g_minishell.oldpwd);
		g_minishell.oldpwd = _strdup(prev);
	}
}

void	change_envp_pwd(void)
{
	t_list	*envpl;
	t_envp	*envp;
	char	*path;

	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!_strcmp(envp->key, "PWD"))
		{
			if (envp->value)
				free(envp->value);
			path = getcwd(NULL, 256);
			envp->value = _strdup(path);
			free(path);
			break ;
		}
		envpl = envpl->next;
	}
}

void	change_envp_oldpwd(void)
{	
	t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!_strcmp(envp->key, "OLDPWD"))
		{
			if (envp->value)
				free(envp->value);
			envp->value = _strdup(g_minishell.oldpwd);
			break ;
		}
		envpl = envpl->next;
	}
}

void	change_values(char *now)
{
	change_global_oldpwd(now);
	change_envp_pwd();
	change_envp_oldpwd();
}

void	change_to_old_path(char *now)
{
	if (!g_minishell.oldpwd)
	{
		_putendl_fd("bash: cd: OLDPWD not set", 2);
		return ;
	}
	else
	{
		if (chdir(g_minishell.oldpwd))
		{
			_putstr_fd("bash: cd: ", 2);
			_putstr_fd(g_minishell.oldpwd, 2);
			_putendl_fd(": No such file or directory", 2);
			g_minishell.exit_status = 1;
			return ;
		}
		_putendl_fd(g_minishell.oldpwd, 1);
	}
	change_values(now);
}
