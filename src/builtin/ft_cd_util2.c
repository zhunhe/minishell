/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:54:06 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 03:54:07 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "util.h"

void	print_error_cd(char *path)
{
	_putstr_fd("bash: cd: ", 2);
	_putstr_fd(path, 2);
	_putendl_fd(": No such file or directory", 2);
	g_minishell.state = 1;
}
