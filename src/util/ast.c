/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:22:10 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 13:03:07 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <util.h>

t_node	*create_node(char *data)
{
	t_node	*new;

	new = _calloc(sizeof(t_node), 1);
	new->file_name = data;
	new->type = get_type(data);
	return (new);
}

void	remove_ast(t_node *node)
{
	t_node	*next;

	while (node != NULL)
	{
		next = node->left;
		node_remover((void *)node->right);
		node_remover((void *)node);
		node = next;
	}
}

t_node	*get_left_leaf_node(t_node *root)
{
	t_node	*last;

	if (root == NULL)
		return (NULL);
	last = root;
	while (last->left != NULL)
		last = last->left;
	return (last);
}

void	add_left_leaf_to_child(t_node **root, t_node *child, bool left)
{
	t_node	*left_leaf;

	if (root == NULL || child == NULL)
		return ;
	if (*root == NULL)
	{
		*root = child;
		return ;
	}
	left_leaf = get_left_leaf_node(*root);
	if (left)
		left_leaf->left = child;
	else
		left_leaf->right = child;
}
