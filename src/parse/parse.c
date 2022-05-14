/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/14 18:14:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

t_list	*parse(char *s, int *status)
{
	t_list	*token;
	t_list	*result;
	t_exec	*exec;
	char	**ss;
	int		i;
	int		heredoc_idx;

	if (check_error(s, status) == ERROR)
		return (NULL);
	ss = _split(s, '|');
	i = -1;
	token = NULL;
	result = NULL;
	heredoc_idx = 0;
	while (ss[++i] != NULL)
	{
		token = tokenize(ss[i]);
		if (token == NULL)
		{
			*status = STATUS_SYNTAX_ERROR;
			break ;
		}
		exec = make_exec(token, status, &heredoc_idx);
		add_list_back(&result, create_list(exec));
		remove_all_list(&token, NULL);
	}
	_split_free(ss);
	return (result);
}
