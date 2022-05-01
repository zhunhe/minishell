/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:02:31 by juhur             #+#    #+#             */
/*   Updated: 2022/05/01 16:28:20 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <util.h>

t_list	*create_list(void *data)
{
	t_list	*new;

	new = _calloc(sizeof(t_list), 1);
	new->data = data;
	return (new);
}

t_list	*get_last_list(t_list *list)
{
	t_list	*last;

	if (list == NULL)
		return (NULL);
	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	add_list_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (list == NULL || new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = get_last_list(*list);
	last->next = new;
}
