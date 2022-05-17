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
	write(2, "bash: ", 6);
	write(2, filename, _strlen(filename));
	write(2, ": ", 2);
	write(2, err_message, _strlen(err_message));
	write(2, "\n", 1);
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
