/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:34:12 by juhur             #+#    #+#             */
/*   Updated: 2022/05/21 19:24:41 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <util.h>

static int	count_word(const char *s, const char c)
{
	int		count;
	int		i;
	bool	quote;
	bool	dquote;

	quote = false;
	dquote = false;
	count = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c) && !quote && !dquote)
			count++;
		if (s[i] == '\'' && !dquote)
			quote ^= true;
		else if (s[i] == '\"' && !quote)
			dquote ^= true;
	}
	if (quote || dquote)
		return (-1);
	return (count);
}

static void	make_word(int len, char **ret, char *s)
{
	char	*arr;

	arr = _calloc(len + 1, sizeof(char));
	*ret = arr;
	while (len)
		*(arr++) = *(s - len--);
	*arr = '\0';
}

static void	make_array(char **ret, char *s, char c, int word_cnt)
{
	int		len;
	bool	quote;
	bool	dquote;

	quote = false;
	dquote = false;
	while (word_cnt--)
	{
		while (*s != '\0' && *s == c)
			++s;
		len = 0;
		while (*s && (c != *s || quote || dquote))
		{
			if (*s == '\'' && !dquote)
				quote ^= true;
			else if (*s == '\"' && !quote)
				dquote ^= true;
			++s;
			++len;
		}
		make_word(len, ret, s);
		++ret;
	}
}

char	**_split(const char *s, const char c)
{
	char	**ret;
	int		word_cnt;

	if (s == NULL)
		return (NULL);
	word_cnt = count_word((char *)s, c);
	if (word_cnt == -1)
		return (NULL);
	ret = _calloc(word_cnt + 1, sizeof(char *));
	make_array(ret, (char *)s, c, word_cnt);
	return (ret);
}
