/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/04/27 15:43:28 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <ast.h>

#define PRINT	1

#if PRINT
#include <stdio.h>
static void	print_ast_from_top(t_ast *ast) {
	t_node	*cur;

	cur = ast->root;
	while (cur) {
		printf("%d\n", cur->type);
		if (cur->right)
			printf("%d\n", cur->right->type);
		cur = cur->left;
	}
}
#endif

void	parse(char *s)
{
	t_ast	*ast;
	char	**ss;

	ss = _split(s, ' ');
	if (!ss)
		return ;
	ast = create_ast(ss);
	if (!ast)
		return ;
#if PRINT
	print_ast_from_top(ast);
#endif
}
