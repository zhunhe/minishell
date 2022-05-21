/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/21 20:29:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <parse.h>
#include <util.h>

t_node_type	get_type(char *str)
{
	if (!_strncmp(str, "<<", 2))
		return (TYPE_HEREDOC);
	if (!_strncmp(str, ">>", 2))
		return (TYPE_OUT_APPEND);
	if (!_strncmp(str, "<", 1))
		return (TYPE_IN_OVERWRITE);
	if (!_strncmp(str, ">", 1))
		return (TYPE_OUT_OVERWRITE);
	return (TYPE_ETC);
}

static bool	check_syntax_error(t_list *result)
{
	t_list	*list;
	t_node	*ast;

	list = result;
	while (list != NULL)
	{
		ast = ((t_exec *)list->data)->root;
		while (ast != NULL)
		{
			if (ast->type < TYPE_CMD && ast->right == NULL)
				return (true);
			if (ast->type == TYPE_HEREDOC && ast->right->heredoc_idx == 0)
				return (true);
			ast = ast->left;
		}
		list = list->next;
	}
	return (false);
}

t_list	*parse(char *s, int *status)
{
	t_list	*token;
	t_list	*result;
	char	**ss;
	int		i;
	int		heredoc_idx;

	if (check_error(s, status) == ERROR)
		return (NULL);
	ss = _split(s, '|');
	result = NULL;
	heredoc_idx = 0;
	i = -1;
	while (ss[++i] != NULL)
	{
		token = tokenize(ss[i]);
		if (token == NULL)
		{
			*status = STATUS_SYNTAX_ERROR;
			break ;
		}
		add_list_back(&result, create_list(make_exec(token, &heredoc_idx, status)));
		free_token(&token);
	}
	_free_double_pointer((void ***)&ss);
	token = get_last_list(result);
	((t_exec *)token->data)->pipe_exist = false;
	if (*status == STATUS_OK && check_syntax_error(result))
		*status = STATUS_SYNTAX_ERROR;
	return (result);
}
