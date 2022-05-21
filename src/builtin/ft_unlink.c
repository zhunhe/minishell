/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:51:39 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 18:51:41 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parse.h"

void	unlink_all(t_list *heredoc)
{
	t_list		*iter;
	t_heredoc	*data;

	iter = heredoc;
	while (iter)
	{
		data = iter->data;
		if (unlink(data->file_name))
			exit(1);
		iter = iter->next;
	}
}
