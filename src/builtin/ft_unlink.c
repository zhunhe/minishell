/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:51:39 by hena              #+#    #+#             */
/*   Updated: 2022/05/22 12:44:22 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "parse.h"

void	unlink_all(t_list *heredoc)
{
	t_list		*iter;
	t_heredoc	*data;
	int			fd;

	iter = heredoc;
	while (iter)
	{
		data = iter->data;
		fd = open(data->file_name, O_RDONLY, 0644);
		if (fd != -1 && unlink(data->file_name))
			exit(1);
		iter = iter->next;
	}
}
