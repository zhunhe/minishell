/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:19:41 by juhur             #+#    #+#             */
/*   Updated: 2022/05/10 18:45:49 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "parse.h"

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

t_node		*create_node(char *data);
t_node		*get_last_left_node(t_ast *ast);
#endif