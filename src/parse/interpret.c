/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:25:52 by juhur             #+#    #+#             */
/*   Updated: 2022/05/21 15:06:34 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <minishell.h>
#include <util.h>

char	*ft_strjoin1(char *s1, char *s2, bool s2_free)
{
	char	*result;

	result = _calloc(_strlen(s1) + _strlen(s2) + 1, sizeof(char));
	_strlcat(result, s1, _strlen(s1) + 1);
	_strlcat(result, s2, _strlen(s1) + _strlen(s2) + 1);
	_free((void **)&s1);
	if (s2_free)
		_free((void **)&s2);
	return (result);
}

int	find_var(char *str, char **result)
{
	int		i;
	char	*key;

	*str = '\0';
	if (*(++str) == '?')
	{
		*result = _itoa(g_minishell.state / 256);
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
		if (str[len] == '$'&& (_isalnum(str[len + 1]) || _strchr("?_", str[len + 1])))
		{
			jump = find_var(str + len, &re);
			*result = ft_strjoin1(*result, str, false);
			*result = ft_strjoin1(*result, re, true);
			str += len + jump + 1;
			i += len + jump + 1;
			len = -1;
		}
	}
	str[len] = '\0';
	i += len;
	*result = ft_strjoin1(*result, str, false);
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

char	*interpret(char *line)
{
	char	*ret;
	char	*str;
	char	*result;
	int		len;
	int		jump;
	char	*tmp;

	str = _strdup(line);
	tmp = str;
	ret = _strdup("");
	len = -1;
	while (str[++len] != '\0')
	{
		if (_strchr("\'\"", str[len]) || (str[len] == '$' && (_isalnum(str[len + 1]) || _strchr("_?", str[len + 1]))))
		{
			jump = change_line(str + len, &result);
			ret = ft_strjoin1(ret, str, false);
			ret = ft_strjoin1(ret, result, true);
			str += len + jump + 1;
			len = -1;
		}
	}
	ret = ft_strjoin1(ret, str, false);
	_free((void **)&tmp);
	return (ret);
}
