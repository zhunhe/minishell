/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:02:31 by juhur             #+#    #+#             */
/*   Updated: 2022/05/12 16:21:46 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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

int	count_list_node(t_list *list)
{
	int	count;

	if (list == NULL)
		return (0);
	count = 1;
	while (list->next != NULL)
	{
		++count;
		list = list->next;
	}
	return (count);
}

void	remove_all_list(t_list **list, void (*remove)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (list == NULL)
		return ;
	cur = *list;
	while (cur != NULL)
	{
		next = cur->next;
		if (remove != NULL)
			remove(cur->data);
		free(cur);
		cur = next;
	}
	*list = NULL;
}
