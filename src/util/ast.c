/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:22:10 by juhur             #+#    #+#             */
/*   Updated: 2022/05/14 18:04:51 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <util.h>

t_node	*create_node(char *data)
{
	t_node	*new;

	new = _calloc(sizeof(t_node), 1);
	new->type = get_type(data);
	return (new);
}

void	add_node_root(t_node **root, t_node *new)
{
	t_node	*old_root;

	if (root == NULL || new == NULL)
		return ;
	if (*root == NULL)
	{
		*root = new;
		return ;
	}
	old_root = *root;
	*root = new;
	new->left = old_root;
}

void	add_node_right(t_node **parent, t_node *child)
{
	if (parent == NULL || child == NULL)
		return ;
	if (*parent == NULL)
	{
		*parent = child;
		return ;
	}
	(*parent)->right = child;
}