/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:48:29 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 22:48:30 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "built_in.h"
#include "util.h"

int	is_valid_idenfier(char *str)
{
	if (!(_isalpha(*str) || *str == '_'))
		return (FALSE);
	while (*str)
	{
		if (!(_isalnum(*str) || *str == '_'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	get_equal_index(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			flag = 1;
			break ;
		}
		++i;
	}
	if (!flag)
		return (-1);
	return (i);
}

void	set_key_value(char *str, char **key, char **value, int index)
{
	int	i;
	int	len;

	i = -1;
	len = _strlen(str);
	if (index == -1)
		*key = make_key(str, len, &i);
	else
	{
		*key = make_key(str, index, &i);
		*value = make_value(str, len, index, &i);
	}
}

void	find_or_change_envp(char *key, char *value)
{
	t_list	*envpl;
	t_envp	*envp;
	int		exist_flag;

	exist_flag = 0;
	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)(envpl)->data;
		if (!_strcmp((envp)->key, key))
		{
			if (value)
			{
				free((envp)->value);
				(envp)->value = _strdup(value);
			}
			exist_flag = 1;
			break ;
		}
		(envpl) = (envpl)->next;
	}
	if (!exist_flag)
	{
		add_key_value(envpl, envp, key, value);
	}	
}

int	divide_argv(char **argv)
{
	int		err_flag;
	int		index;
	char	*key;
	char	*value;

	err_flag = 0;
	while (*argv)
	{
		key = NULL;
		value = NULL;
		index = get_equal_index(*argv);
		set_key_value(*argv, &key, &value, index);
		if (!is_valid_idenfier(key))
		{
			ft_print_export_error(*argv);
			err_flag = 1;
		}
		else
			find_or_change_envp(key, value);
		free(key);
		free(value);
		argv++;
	}
	return (err_flag);
}
