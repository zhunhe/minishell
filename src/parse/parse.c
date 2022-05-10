/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/10 17:36:04 by juhur            ###   ########.fr       */
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

t_status	parse(char *s)
{
	t_list	*token;
	char	**ss;
	int		i;
	void	(*func)(void *);

	func = remove_token;
	if (check_error(s) != STATUS_OK)
		return (g_minishell.status);
	ss = _split(s, '|');
	i = -1;
	while (ss[++i] != NULL)
	{
		token = tokenize(ss[i]);
		// TODO: 파이프 사이에 ' '만 있다는 뜻 -> 모든 리스트 삭제하고 에러 처리
		// bash: syntax error near unexpected token `|'
		if (token == NULL)
			;
		remove_list(&token, func);
	}
	return (STATUS_OK);
}
