/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:23:55 by juhur             #+#    #+#             */
/*   Updated: 2022/04/29 23:00:25 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <minishell.h>
#include <util.h>

#define PRINT	1

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

	data = (t_envp *)malloc(sizeof(t_envp));
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