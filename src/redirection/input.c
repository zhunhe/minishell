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

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


//TODO:: open말고 다른 방법 확인
void	input(char *filename, int dup_fd)
{
	int	fd;
#if 0	// COMPILE ERROR
	int	ret;
#endif

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "bash: permission denied\n", 24);
		exit(1);
	}
	dup2(fd, dup_fd);
	close(fd);
}
