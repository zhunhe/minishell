/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/09 18:34:40 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minishell.h>
#include <ast.h>
#include <util.h>

t_status	parse(char *s)
{
	t_list	*token;
	char	**ss;
	int		i;

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
		// TODO: token_free()
	}
	return (STATUS_OK);
}
