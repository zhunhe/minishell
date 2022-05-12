/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:04:30 by juhur             #+#    #+#             */
/*   Updated: 2022/05/13 05:11:36 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <util.h>

size_t	_strlen(char *s)
{
	char	*e;

	e = s;
	while (*e)
		++e;
	return (e - s);
}
