/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:02:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 15:47:30 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <util.h>
#include <parse.h>
#include <minishell.h>

char	*find_rdr(char *s1, char *charset)
{
	bool	quote;
	bool	dquote;

	quote = false;
	dquote = false;
	while (*s1 != '\0')
	{
		if (*s1 == '\'' && !dquote)
			quote ^= true;
		else if (*s1 == '\"' && !quote)
			dquote ^= true;
		if (!quote && !dquote && _strchr(charset, *s1))
			return ((char *)s1);
		++s1;
	}
	return ((char *)s1);
}

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
		len = find_rdr(*s, "<>") - *s;
		data = _strndup(*s, len);
		*s += len;
	}
	return (data);
}

t_list	*tokenize(char *s)
{
	t_list		*head;

	_strskip(&s, " \t");
	head = NULL;
	while (*s != '\0')
	{
		add_list_back(&head, create_list(make_token(&s)));
		_strskip(&s, " \t");
	}
	return (head);
}
