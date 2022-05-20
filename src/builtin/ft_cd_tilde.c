/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_tilde.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:33:59 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 04:34:00 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "minishell.h"
#include "built_in.h"

void	use_tilde(char *str, char *now)
{
	const char	*tilde = "/Users/juhur";
	int			len;
	char		*path;
	int			i;
	int			j;

	i = -1;
	j = -1;
	len = _strlen(str) + _strlen((char *)tilde);
	path = malloc(sizeof(char) * len);
	if (!path)
		exit(1);
	while (++i < (int)_strlen((char *)tilde))
		path[i] = tilde[i];
	while (++j < (int)_strlen(str) - 1)
		path[i + j] = str[j + 1];
	path[len - 1] = 0;
	if (chdir(path))
		g_minishell.state = 1;
	else
		change_values(now);
}
