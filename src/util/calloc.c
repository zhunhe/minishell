/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:19:35 by juhur             #+#    #+#             */
/*   Updated: 2022/05/20 15:17:07 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	malloc_error(void)
{
	printf("minishell: insufficient memory\n");
	exit(1);
}

void	*_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ret = malloc(size * count);
	if (ret == NULL)
		malloc_error();
	i = 0;
	while (i < count * size)
	{
		*(unsigned char *)(ret + i) = 0;
		++i;
	}
	return (ret);
}
