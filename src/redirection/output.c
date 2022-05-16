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

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#ifndef FD_OPTION
# define FD_OPTION
# define READ 0
# define WRITE 1
# define STDIN 0
# define STDOUT 1
# define STDERR 2
#endif

/*
 * 찾아봐야 할 점 WROnly처리 일까 RDWR처리 일까
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
	write(2, err_message, strlen(err_message));
	write(2, "\n", 1);
}

void	output(char *filename, int dup_fd)
{
	int	file_descriptor;

	file_descriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (file_descriptor < 0)
	{
		print_error(filename);
		exit(1); // TODO:: exit 값 확인하기
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
		exit(1); // TODO:: exit 값 확인하기
	}
	dup2(file_descriptor, dup_fd);
	close(file_descriptor);
}
