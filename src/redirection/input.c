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

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static void	print_error(char *filename)
{
	char	*err_message;

	err_message = strerror(errno);
	write(2, "bash: ", 6);
	write(2, filename, strlen(filename)); //TODO:: strlen -> ft_strlen 넣어야 함
	write(2, ": ", 2);
	write(2, err_message, strlen(err_message));
	write(2, "\n", 1);
}

void	input(char *filename, int dup_fd)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error(filename);
		exit(1);
	}
	dup2(fd, dup_fd);
	close(fd);
}
