/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:59:52 by juhur             #+#    #+#             */
/*   Updated: 2022/05/01 16:14:06 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

int		_strlen(char *s);
int		_strcmp(const char *s1, const char *s2);
char	*_strdup(char *s);
void	*_calloc(size_t count, size_t size);

#endif