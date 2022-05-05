/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:19:41 by juhur             #+#    #+#             */
/*   Updated: 2022/05/06 00:39:27 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum e_node_type
{
	NODE_IN_OVERWRITE,
	NODE_OUT_OVERWRITE,
	NODE_HEREDOC,
	NODE_OUT_APPEND,
	NODE_CMD,
	NODE_ETC
}	t_node_type;

typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
	t_node_type		type;
}	t_node;

typedef struct s_ast
{
	struct s_node	*root;
}	t_ast;

t_node_type	get_type(char *str);
t_node		*create_node(char *data);
t_node		*get_last_left_node(t_ast *ast);
void		create_ast(t_ast *ast, char *s);

#endif