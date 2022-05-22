/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:53:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/21 20:29:44 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <list.h>
#include <util.h>

void	free_token(t_list **token)
{
	void	(*remover)(void *);

	if (token != NULL && *token != NULL)
	{
		remover = data_remover;
		remove_all_list(token, remover);
	}
}

void	free_lists(t_list **heredoc, t_list **exec)
{
	void	(*remover)(void *);

	if (heredoc != NULL && *heredoc != NULL)
	{
		remover = heredoc_remover;
		remove_all_list(heredoc, remover);
	}
	if (exec != NULL && *exec != NULL)
	{
		remover = exec_remover;
		remove_all_list(exec, remover);
	}
}
