/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:59:52 by juhur             #+#    #+#             */
/*   Updated: 2022/05/06 03:39:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>

/*
** string.c
*/
int		_strlen(char *s);
char	*_strdup(char *s);
size_t	_strlcat(char *dst, const char *src, size_t dstsize);
int		_strncmp(const char *s1, const char *s2, size_t n);

/*
** stdlib.c
*/
void	*_calloc(size_t count, size_t size);

/*
** split.c
*/
void		_split_free(char **ss);
char		**_split(const char *s, const char c);

#endif