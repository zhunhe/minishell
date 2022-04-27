/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:12:30 by juhur             #+#    #+#             */
/*   Updated: 2022/04/27 15:04:31 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_strlen(char *s)
{
	char	*e;

	e = s;
	while (*e)
		++e;
	return (e - s);
}

int	_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}
