/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:59:52 by juhur             #+#    #+#             */
/*   Updated: 2022/05/03 10:42:31 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>

/*
** string.c
*/
int		_strlen(char *s);
int		_strcmp(const char *s1, const char *s2);
char	*_strdup(char *s);
size_t	_strlcat(char *dst, const char *src, size_t dstsize);

/*
** stdlib.c
*/
void	*_calloc(size_t count, size_t size);

#endif