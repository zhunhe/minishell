/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:40:04 by juhur             #+#    #+#             */
/*   Updated: 2022/05/20 06:32:02 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <util.h>

char	*_strjoin_free(char *old, char *s, bool s_free)
{
	char	*new;
	size_t	old_len;
	size_t	s_len;

	if (s == NULL)
		return (old);
	s_len = _strlen(s);
	if (old == NULL)
		return (_strdup(s));
	old_len = _strlen(old);
	new = _calloc(old_len + s_len + 1, sizeof(char));
	_strlcat(new, old, old_len + 1);
	free(old);
	_strlcat(new, s, old_len + s_len + 1);
	if (s_free)
		free(s);
	return (new);
}
