/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:05:08 by juhur             #+#    #+#             */
/*   Updated: 2022/05/13 04:08:44 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <util.h>

char	*_strdup(char *s)
{
	char	*new;
	char	*ptr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = _strlen(s);
	new = _calloc(s_len + 1, sizeof(char));
	ptr = new;
	while (s_len--)
		*(ptr++) = *(s++);
	return (new);
}