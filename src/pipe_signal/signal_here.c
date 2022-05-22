/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_here.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:25:15 by hena              #+#    #+#             */
/*   Updated: 2022/05/22 12:42:52 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>


void	sig_heredoc_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	dup2(0, 200);
	close(0);
	g_minishell.exit_status = 1;
	g_minishell.signal = 1;
}
