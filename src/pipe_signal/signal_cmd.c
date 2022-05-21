/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:22:45 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 19:10:32 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minishell.h"
#include "util.h"

void	sig_cmd_int_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	g_minishell.exit_status = 130;
	_putendl_fd("", 2);
}

void	sig_cmd_quit_handler(int signal)
{
	if (signal != SIGQUIT)
		return ;
	g_minishell.exit_status = 131;
	_putendl_fd("Quit: 3", 2);
}
