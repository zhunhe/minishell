/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 00:00:54 by juhur             #+#    #+#             */
/*   Updated: 2022/05/20 14:19:43 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <minishell.h>
#include <util.h>

static bool	check_invalid_char(char *s, int *status)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '\\' || s[i] == ';')
		{
			*status = STATUS_ERROR_INVALID_CHAR;
			return (ERROR);
		}
	}
	return (OK);
}

static bool	check_quotes_closed(char *s, int *status)
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
		*status = STATUS_ERROR_QUOTES_OPENED;
		return (ERROR);
	}
	return (OK);
}

static bool	check_double_pipe(char *s, int *status)
{
	size_t	s_len;
	size_t	i;

	s_len = _strlen(s);
	i = 0;
	while (i < s_len - 1)
	{
		if (!_strncmp(s, "||", 2))
		{
			*status = STATUS_SYNTAX_ERROR;
			return (ERROR);
		}
		++i;
	}
	return (OK);
}

bool	check_error(char *s, int *status)
{
	if (check_invalid_char(s, status))
		return (ERROR);
	if (check_quotes_closed(s, status))
		return (ERROR);
	if (check_double_pipe(s, status))
		return (ERROR);
	return (OK);
}
