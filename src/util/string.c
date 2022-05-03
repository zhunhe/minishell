/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:12:30 by juhur             #+#    #+#             */
/*   Updated: 2022/05/03 10:40:16 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <minishell.h>
#include <util.h>

int	_strlen(char *s)
{
	char	*e;

	if (s == NULL)
		return (0);
	e = s;
	while (*e)
		++e;
	return (e - s);
}

int	_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

char	*_strdup(char *s)
{
	char	*new;
	int		s_len;
	int		i;

	if (s == NULL)
		return (NULL);
	s_len = _strlen(s);
	new = _calloc(s_len + 1, sizeof(char));
	i = -1;
	while (++i < s_len)
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}

size_t	_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dst_len;
	size_t	src_len;

	dst_len = _strlen(dst);
	src_len = _strlen((char *)src);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	idx = 0;
	while ((dst_len + idx < dstsize - 1)
		&& (src[idx]))
	{
		dst[dst_len + idx] = src[idx];
		++idx;
	}
	dst[dst_len + idx] = 0;
	return (dst_len + src_len);
}
