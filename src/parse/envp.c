/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:23:55 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 12:40:21 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <util.h>

t_envp	*s_to_key_value(char *s)
{
	t_envp	*envp;
	char	**ss;

	envp = _calloc(sizeof(t_envp), 1);
	ss = _split(s, '=');
	envp->key = _strdup(ss[KEY]);
	envp->value = _strdup(ss[VALUE]);
	_free_double_pointer((void ***)&ss);
	return (envp);
}

void	set_envp(char **ss)
{
	int		i;

	i = -1;
	while (ss[++i] != NULL)
		add_list_back(&g_minishell.envp, create_list(s_to_key_value(ss[i])));
}

char	**get_envp_double_pointer(void)
{
	int		count;
	char	**ss;
	int		i;
	t_envp	*e;
	t_list	*list;

	list = g_minishell.envp;
	count = count_list_node(list);
	ss = _calloc(count + 1, sizeof(char *));
	i = 0;
	while (i < count)
	{
		e = list->data;
		ss[i] = _strdup(e->key);
		if (e->value != NULL)
		{
			ss[i] = _strjoin_free(ss[i], "=", false);
			ss[i] = _strjoin_free(ss[i], e->value, false);
		}
		list = list->next;
		++i;
	}
	return (ss);
}

char	*get_envp_value(char *key)
{
	t_list	*list;
	t_envp	*envp;

	list = g_minishell.envp;
	while (list != NULL)
	{
		envp = list->data;
		if (!_strcmp(key, envp->key))
			return (envp->value);
		list = list->next;
	}
	return (NULL);
}
