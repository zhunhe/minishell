/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:22:10 by juhur             #+#    #+#             */
/*   Updated: 2022/05/06 15:44:37 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <util.h>

t_node_type	get_type(char *str)
{
	if (!_strncmp(str, "<", 1))
		return (NODE_IN_OVERWRITE);
	if (!_strncmp(str, ">", 1))
		return (NODE_OUT_OVERWRITE);
	if (!_strncmp(str, "<<", 2))
		return (NODE_HEREDOC);
	if (!_strncmp(str, ">>", 2))
		return (NODE_OUT_APPEND);
	return (NODE_ETC);
}

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

t_ast	*create_ast(char **ss)
{
	t_ast	*ast;
	t_node	*tmp;
	int		i;

	ast = _calloc(sizeof(t_ast), 1);
	if (ss[1] == NULL)
	{
		ast->root = create_node(ss[0]);
		ast->root->type = NODE_CMD;
		return (ast);
	}
	ast->root = create_node(ss[1]);
	i = 1;
	while (ss[++i] != NULL)
	{
		tmp = get_last_left_node(ast);
		if (i & 1)
			tmp->left = create_node(ss[i]);
		else
			tmp->right = create_node(ss[i]);
	}
	tmp = get_last_left_node(ast);
	tmp->left = create_node(ss[0]);
	tmp->left->type = NODE_CMD;
	return (ast);
}
