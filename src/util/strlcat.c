/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:06:45 by juhur             #+#    #+#             */
/*   Updated: 2022/05/13 05:11:39 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <util.h>

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
