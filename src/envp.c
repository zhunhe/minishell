/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:23:55 by juhur             #+#    #+#             */
/*   Updated: 2022/04/29 16:30:57 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minishell.h>

#define PRINT	1

#if PRINT
void	print_envp_list(void)
{
	t_list	*tmp;

	tmp = g_minishell.envp;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}
#endif

void	set_envp(char **envp)
{
	for (int i = 0; envp[i]; i++)
		add_list_back(&g_minishell.envp, create_list(envp[i]));
#if PRINT
	print_envp_list();
#endif
}