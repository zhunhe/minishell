/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:57:19 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 21:57:21 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "util.h"
#include <stdlib.h>

t_list	*init_list(void)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		exit(1);
	tmp->data = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_envp	*init_envp(char *key, char *value)
{
	t_envp	*tmp;

	tmp = (t_envp *)malloc(sizeof(t_envp));
	if (!tmp)
		exit(1);
	tmp->key = _strdup(key);
	tmp->value = _strdup(value);
	return (tmp);
}

char	*make_key(char *str, int len, int *i)
{
	char	*key;

	*i = -1;
	key = (char *)malloc(sizeof(char) * len + 1);
	while (++(*i) < len)
		key[*i] = str[*i];
	key[len] = 0;
	return (key);
}

char	*make_value(char *str, int len, int index, int *i)
{
	char	*value;
	int		j;

	j = -1;
	value = (char *)malloc(sizeof(char) * (len - index));
	if (!value)
		exit(1);
	++(*i);
	while (++j < len - index - 1)
		value[j] = str[*i + j];
	value[j] = 0;
	return (value);
}

void	add_key_value(t_list *envpl, t_envp	*envp, char *key, char *value)
{
	t_list	*last;

	last = g_minishell.envp;
	while ((last)->next)
		(last) = (last)->next;
	envpl = init_list();
	envp = init_envp(key, value);
	envpl->data = envp;
	last->next = envpl;
}
