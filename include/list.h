/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:02:42 by juhur             #+#    #+#             */
/*   Updated: 2022/05/10 17:29:39 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*create_list(void *data);
t_list	*get_last_list(t_list *list);
void	add_list_back(t_list **list, t_list *new);
int		count_list_node(t_list *list);
void	remove_list(t_list **list, void (*remove)(void *));

#endif