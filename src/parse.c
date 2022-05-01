/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/02 00:04:26 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minishell.h>
#include <ast.h>

#define PRINT	0

#if PRINT
static void	print_ast_from_top(t_ast *ast)
{
	t_node	*cur;

	cur = ast->root;
	while (cur)
	{
		printf("%d\n", cur->type);
		if (cur->right)
			printf("%d\n", cur->right->type);
		cur = cur->left;
	}
}
#endif

t_status	parse(char *s)
{
	t_ast	*ast;
	char	**ss;

	if (check_error(s) != STATUS_OK)
		return (g_minishell.status);
	ss = _split(s, ' ');
	ast = create_ast(ss);
#if PRINT
	print_ast_from_top(ast);
#endif
	return (STATUS_OK);
}
