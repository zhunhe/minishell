/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:25:52 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 16:43:01 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <util.h>

int	find_var(char *str, char **result)
{
	int		i;
	char	*key;

	*str = '\0';
	if (*(++str) == '?')
	{
		*result = _itoa(g_minishell.exit_status);
		return (1);
	}
	i = 0;
	while (str[i] && (_isalnum(str[i]) || str[i] == '_'))
		++i;
	key = _strndup(str, i + 1);
	key[i] = '\0';
	if (get_envp_value(key))
		*result = _strdup(get_envp_value(key));
	else
		*result = _strdup("");
	_free((void **)&key);
	return (i);
}

int	find_dquote(char *str, char **result)
{
	int		i;
	int		jump;
	int		len;
	char	*re;

	i = 0;
	*result = _strdup("");
	len = -1;
	while (str[++len] != '\"')
	{
		if (str[len] == '$' && \
		(_isalnum(str[len + 1]) || _strchr("?_", str[len + 1])))
		{
			jump = find_var(str + len, &re);
			*result = _strjoin_free(*result, str, false);
			*result = _strjoin_free(*result, re, true);
			str += len + jump + 1;
			i += len + jump + 1;
			len = -1;
		}
	}
	str[len] = '\0';
	i += len;
	*result = _strjoin_free(*result, str, false);
	return (i + 1);
}

int	change_line(char *str, char **result)
{
	int	i;

	i = 0;
	if (*str == '\'')
	{
		*(str++) = 0;
		while (str[i] != '\'')
			i++;
		str[i] = '\0';
		*result = _strdup(str);
		return (i + 1);
	}
	else if (*str == '$')
		return (find_var(str, result));
	else if (*str == '\"')
	{
		*(str++) = '\0';
		return (find_dquote(str, result));
	}
	return (0);
}

static char	*interpret_main(char *s)
{
	char	*ret;
	char	*result;
	int		len;
	int		jump;

	ret = _strdup("");
	len = -1;
	while (s[++len] != '\0')
	{
		if (s[len] == '$' && (s[len + 1] == '\0' || _strchr(" \t", s[len + 1])))
			;
		else if (_strchr("\'\"", s[len]) || \
		(s[len] == '$' && (_isalnum(s[len + 1]) || _strchr("_?", s[len + 1]))))
		{
			jump = change_line(s + len, &result);
			ret = _strjoin_free(ret, s, false);
			ret = _strjoin_free(ret, result, true);
			s += len + jump + 1;
			len = -1;
		}
	}
	ret = _strjoin_free(ret, s, false);
	return (ret);
}

char	*interpret(char *line)
{
	char	*s;
	char	*ret;

	s = _strdup(line);
	ret = interpret_main(s);
	_free((void **)&s);
	return (ret);
}
