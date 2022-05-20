/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:47:18 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 10:03:39 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"

void	here_doc(int index, int dup_fd, t_list *heredoc)
{
	t_list		*iter;
	t_heredoc	*h_iter;
	int			fd;
	int			i;

	i = 0;
	iter = heredoc;
	while (++i < index)
		iter = iter->next;
	h_iter = (t_heredoc *)iter->data;
	fd = open(h_iter->file_name, O_RDWR, 0644);
	if (fd < 0)
		exit(1);
	dup2(fd, dup_fd);
	close(fd);
}
