/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:59:52 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 15:34:58 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdbool.h>
# include <stddef.h>

void	*_calloc(size_t count, size_t size);
void	_free(void **target);
void	_free_double_pointer(void ***target);
int		_isupper(char c);
int		_islower(char c);
int		_isalpha(char c);
int		_isdigit(char c);
int		_isalnum(char c);
char	*_itoa(int n);
void	_putendl_fd(char const *s, int fd);
void	_putstr_fd(char const *s, int fd);
char	**_split(const char *s, const char c);
char	*_strchr(const char *s, int c);
int		_strcmp(char *s1, char *s2);
char	*_strdup(char *s);
char	*_strjoin_free(char *old, char *s, bool s_free);
size_t	_strlcat(char *dst, const char *src, size_t dstsize);
size_t	_strlen(char *s);
int		_strncmp(const char *s1, const char *s2, size_t n);
char	*_strndup(const char *s1, size_t n);
void	_strskip(char **s, char *charset);

#endif