/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 00:00:54 by juhur             #+#    #+#             */
/*   Updated: 2022/05/02 00:07:08 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <minishell.h>

static void	check_invalid_char(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '\\' || s[i] == ';')
		{
			g_minishell.status = STATUS_ERROR_INVALID_CHAR;
			break ;
		}
	}
}

static void	check_quotes_closed(char *s)
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
		g_minishell.status = STATUS_ERROR_QUOTES_OPENED;
}

t_status	check_error(char *s)
{
	if (g_minishell.status == STATUS_OK)
		check_invalid_char(s);
	if (g_minishell.status == STATUS_OK)
		check_quotes_closed(s);
	return (g_minishell.status);
}
