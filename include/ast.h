/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:19:41 by juhur             #+#    #+#             */
/*   Updated: 2022/05/09 18:27:37 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum e_node_type
{
	TYPE_IN_OVERWRITE,
	TYPE_OUT_OVERWRITE,
	TYPE_HEREDOC,
	TYPE_OUT_APPEND,
	TYPE_CMD,
	TYPE_ETC
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
t_ast		*create_ast(char **ss);
#endif