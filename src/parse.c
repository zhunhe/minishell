/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/01 16:33:55 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
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

static t_status	check_invalid_char(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '\\' || s[i] == ';')
		{
			g_minishell.status = STATUS_ERROR_INVALID_CHAR;
			return (g_minishell.status);
		}
	}
	return (STATUS_OK);
}

static t_status	check_quotes_closed(char *s)
{
	int		i;
	bool	quote;
	bool	dquote;

	quote = false;
	dquote = false;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '\'' && !dquote)
			quote ^= true;
		else if (s[i] == '\"' && !quote)
			dquote ^= true;
	}
	if (quote || dquote)
	{
		g_minishell.status = STATUS_ERROR_QUOTES_OPENED;
		return (g_minishell.status);
	}
	return (STATUS_OK);
}

t_status	parse(char *s)
{
	t_ast	*ast;
	char	**ss;

	if (check_invalid_char(s) != STATUS_OK)
		return (g_minishell.status);
	if (check_quotes_closed(s) != STATUS_OK)
		return (g_minishell.status);
	ss = _split(s, ' ');
	ast = create_ast(ss);
#if PRINT
	print_ast_from_top(ast);
#endif
	return (STATUS_OK);
}
