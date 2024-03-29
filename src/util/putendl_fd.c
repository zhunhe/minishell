/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 05:19:43 by hena              #+#    #+#             */
/*   Updated: 2022/05/18 05:19:44 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "util.h"

void	_putendl_fd(char const *s, int fd)
{
	_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
