/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:22:10 by juhur             #+#    #+#             */
/*   Updated: 2022/05/10 18:45:22 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <util.h>

t_node	*create_node(char *data)
{
	t_node	*tmp;

	tmp = _calloc(sizeof(t_node), 1);
	tmp->type = get_type(data);
	return (tmp);
}

t_node	*get_last_left_node(t_ast *ast)
{
	t_node	*last;

	if (ast == NULL)
		return (NULL);
	last = ast->root;
	while (last->left != NULL)
		last = last->left;
	return (last);
}
