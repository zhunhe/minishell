/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:12:30 by juhur             #+#    #+#             */
/*   Updated: 2022/04/30 00:33:18 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	new = (char *)malloc(sizeof(char) * (s_len + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (++i < s_len)
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}