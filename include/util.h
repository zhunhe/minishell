/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:59:52 by juhur             #+#    #+#             */
/*   Updated: 2022/05/13 04:09:01 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>

size_t	_strlen(char *s);
char	*_strdup(char *s);
size_t	_strlcat(char *dst, const char *src, size_t dstsize);
int		_strncmp(const char *s1, const char *s2, size_t n);
char	*_strchr(const char *s, int c);
void	_strskip(char **s, char *charset);
void	*_calloc(size_t count, size_t size);
void	_split_free(char **ss);
char	**_split(const char *s, const char c);
char	*_strndup(const char *s1, size_t n);
char	*_strcharset(const char *s1, char *charset);

void	_putstr_fd(char const *s, int fd);
void	_putendl_fd(char const *s, int fd);
int		_strcmp(char *s1, char *s2);
#endif