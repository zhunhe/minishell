/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:16:27 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 23:16:28 by hena             ###   ########.fr       */
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

char	*find_home_path(int *flag)
{
	t_list	*envpl;
	t_envp	*envp;
	char	*path;

	*flag = 0;
	path = NULL;
	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!_strcmp(envp->key, "HOME"))
		{
			path = envp->value;
			*flag = 1;
			break ;
		}
		envpl = envpl->next;
	}
	return (path);
}

void	using_environment_home_value(char *now)
{
	int		flag;
	char	*path;

	path = find_home_path(&flag);
	if (!flag)
	{
		_putendl_fd("bash: cd: HOME not set", 2);
		g_minishell.state = 1;
		return ;
	}
	if (path == NULL || !_strcmp(path, ""))
		chdir(path);
	else
	{
		if (chdir(path) == -1)
			print_error_cd(path);
		else
			change_values(now);
	}
}

int	go_home_dir(char *argv, char *now)
{
	if (!argv || !_strcmp("--", argv))
	{
		using_environment_home_value(now);
		return (TRUE);
	}
	return (FALSE);
}
