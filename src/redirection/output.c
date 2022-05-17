/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:52:50 by hena              #+#    #+#             */
/*   Updated: 2022/04/23 19:58:17 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "util.h"

/*
 * strerror(); input.c output.c leaks check
 */

/*
 * redirect > 
 */

static void	print_error(char *filename)
{
	char	*err_message;

	err_message = strerror(errno);
	write(2, "bash: ", 6);
	write(2, filename, strlen(filename)); //TODO:: strlen -> ft_strlen 넣어야 함
	write(2, ": ", 2);
	write(2, err_message, _strlen(err_message));
	write(2, "\n", 1);
}

void	output(char *filename, int dup_fd)
{
	int	file_descriptor;

	file_descriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (file_descriptor < 0)
	{
		print_error(filename);
		exit(1);
	}
	dup2(file_descriptor, dup_fd);
	close(file_descriptor);
}

/*
 * redirect >>
 */

void	output_append(char *filename, int dup_fd)
{
	int	file_descriptor;

	file_descriptor = open(filename, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (file_descriptor < 0)
	{
		print_error(filename);
		exit(1);
	}
	dup2(file_descriptor, dup_fd);
	close(file_descriptor);
}
