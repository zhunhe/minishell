/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcharset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:19:51 by juhur             #+#    #+#             */
/*   Updated: 2022/05/09 16:25:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <util.h>

char	*_strcharset(const char *s1, char *charset)
{
	while (*s1 != '\0')
	{
		if (_strchr(charset, *s1))
			return ((char *)s1);
		++s1;
	}
	return ((char *)s1);
}