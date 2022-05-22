/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 14:22:31 by juhur            ###   ########.fr       */
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

static bool	is_redirection(t_node_type type)
{
	if (type == TYPE_IN_OVERWRITE)
		return (true);
	if (type == TYPE_OUT_OVERWRITE)
		return (true);
	if (type == TYPE_HEREDOC)
		return (true);
	if (type == TYPE_OUT_APPEND)
		return (true);
	return (false);
}

static bool	check_syntax_error(t_list *exec)
{
	t_list	*list;
	t_node	*ast;

	list = exec;
	while (list != NULL)
	{
		ast = ((t_exec *)list->data)->root;
		while (ast != NULL)
		{
			if (is_redirection(ast->type) && ast->right == NULL)
				return (true);
			if (ast->type == TYPE_HEREDOC && ast->right->heredoc_idx == 0)
				return (true);
			ast = ast->left;
		}
		list = list->next;
	}
	return (false);
}

static t_list	*parse_main(char **ss, int *status)
{
	t_list	*token;
	t_list	*exec;
	int		heredoc_idx;
	int		i;

	exec = NULL;
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
		add_list_back(&exec, \
			create_list(make_exec(token, &heredoc_idx, status)));
		free_token(&token);
	}
	return (exec);
}

t_list	*parse(char *s, int *status)
{
	t_list	*exec;
	char	**ss;

	if (check_error(s, status) == ERROR)
		return (NULL);
	ss = _split(s, '|');
	exec = parse_main(ss, status);
	_free_double_pointer((void ***)&ss);
	if (*status == STATUS_OK)
	{
		((t_exec *)get_last_list(exec)->data)->pipe_exist = false;
		if (check_syntax_error(exec))
			*status = STATUS_SYNTAX_ERROR;
	}
	return (exec);
}
