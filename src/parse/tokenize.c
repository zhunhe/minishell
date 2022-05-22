/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:02:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 14:21:56 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <util.h>
#include <parse.h>
#include <minishell.h>

static char	*make_token(char **s)
{
	t_node_type	type;
	char		*data;
	size_t		len;

	type = get_type(*s);
	if (type == TYPE_OUT_APPEND || type == TYPE_HEREDOC)
	{
		data = _strndup(*s, 2);
		*s += 2;
	}
	else if (type == TYPE_IN_OVERWRITE || type == TYPE_OUT_OVERWRITE)
	{
		data = _strndup(*s, 1);
		++(*s);
	}
	else
	{
		len = _strcharset(*s, "<>") - *s;
		data = _strndup(*s, len);
		*s += len;
	}
	return (data);
}

t_list	*tokenize(char *s)
{
	t_list		*head;

	_strskip(&s, " ");
	head = NULL;
	while (*s != '\0')
	{
		add_list_back(&head, create_list(make_token(&s)));
		_strskip(&s, " ");
	}
	return (head);
}
