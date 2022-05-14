/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:12:33 by juhur             #+#    #+#             */
/*   Updated: 2022/05/14 21:45:45 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <list.h>
#include <parse.h>
#include <util.h>

t_exec	*make_exec(t_list *token, int *status, int *heredoc_idx)
{
	t_exec  *result;

	(void)status;
	(void)heredoc_idx;
	result = _calloc(1, sizeof(t_exec));
	while (token != NULL)
	{
		printf("%s %d [%s]		", __func__, __LINE__, (char *)token->data);
		token = token->next;
	}
	printf("\n*************************\n");
	return (result);
}
