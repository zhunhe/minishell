/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:55:04 by juhur             #+#    #+#             */
/*   Updated: 2022/05/09 16:01:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <util.h>

char	*_strndup(const char *s1, size_t n)
{
	char	*copied;
	size_t	len;

	len = 0;
	while (len < n && s1[len])
		++len;
	copied = _calloc(len + 1, sizeof(char));
	_strlcat(copied, s1, len + 1);
	return (copied);
}
