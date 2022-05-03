/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:23:55 by juhur             #+#    #+#             */
/*   Updated: 2022/05/03 13:49:40 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minishell.h>
#include <util.h>

#define PRINT	0

#if PRINT
void	print_envp_list(void)
{
	t_list	*tmp;
	t_envp	*envp;

	tmp = g_minishell.envp;
	while (tmp)
	{
		envp = (t_envp *)tmp->data;
		printf("%s=%s\n", envp->key, envp->value);
		tmp = tmp->next;
	}
}
#endif

t_envp	*envp_to_struct(char *s)
{
	t_envp	*data;
	char	**ss;

	data = _calloc(sizeof(t_envp), 1);
	ss = _split(s, '=');
	data->key = _strdup(ss[0]);
	data->value = _strdup(ss[1]);
	_split_free(ss);
	return (data);
}

void	set_envp(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		add_list_back(&g_minishell.envp, create_list(envp_to_struct(envp[i])));
#if PRINT
	print_envp_list();
#endif
}

char	**get_envp_double_pointer(t_list *list)
{
	int		count;
	char	**ss;
	int		i;
	t_envp	*e;

	count = count_list_node(list);
	ss = _calloc(count + 1, sizeof(char));
	i = 0;
	while (i < count)
	{
		e = list->data;
		ss[i] = _calloc(_strlen(e->key) + _strlen(e->value) + 2, sizeof(char));
		_strlcat(ss[i], e->key, _strlen(ss[i]) + _strlen(e->key) + 1);
		_strlcat(ss[i], "=", _strlen(ss[i]) + 2);
		_strlcat(ss[i], e->value, _strlen(ss[i]) + _strlen(e->value) + 1);
		list = list->next;
		++i;
	}
	return (ss);
}
