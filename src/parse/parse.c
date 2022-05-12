/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/13 04:53:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minishell.h>
#include <parse.h>
#include <ast.h>
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

bool	parse(char *s, t_status *status)
{
	t_list	*token;
	char	**ss;
	int		i;

	if (check_error(s, status) == ERROR)
		return (ERROR);
	ss = _split(s, '|');
	i = -1;
	while (ss[++i] != NULL)
	{
		token = tokenize(ss[i]);
		if (token == NULL)
		{
			*status = STATUS_SYNTAX_ERROR;
			break ;
		}
	}
	_split_free(ss);
	remove_all_list(&token, NULL);
	if (*status != STATUS_OK)
		return (ERROR);
	return (OK);
}
