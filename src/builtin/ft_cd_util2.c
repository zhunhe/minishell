/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:54:06 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 18:10:08 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "util.h"

void	print_error_cd(char *path)
{
	_putstr_fd("bash: cd: ", 2);
	_putstr_fd(path, 2);
	_putendl_fd(": No such file or directory", 2);
	g_minishell.exit_status = 1;
}
