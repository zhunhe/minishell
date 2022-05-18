/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:50:38 by hena              #+#    #+#             */
/*   Updated: 2022/05/16 16:04:30 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "util.h"

static void	print_error(char *filename)
{
	char	*err_message;

	err_message = strerror(errno);
	_putstr_fd("bash: ", 2);
	_putstr_fd(filename, 2);
	_putstr_fd(": ", 2);
	_putendl_fd(err_message, 2);
}

void	input(char *filename, int dup_fd)
{
	int	file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor < 0)
	{
		print_error(filename);
		exit(1);
	}
	dup2(file_descriptor, dup_fd);
	close(file_descriptor);
}
