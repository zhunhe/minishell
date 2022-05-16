/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_here.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:25:15 by hena              #+#    #+#             */
/*   Updated: 2022/05/16 16:02:50 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "../includehena/test.h"

extern t_minishell g_minishell;

void	sig_heredoc_handler(int signal)
{
	if (signal != SIGINT)
		return ;
#if 0	// COMPILE ERROR
	printf(">");
#endif
#if 0	// COMPILE ERROR
	if (rl_on_new_line() == -1)
		exit(1);
#endif
#if 0	// COMPILE ERROR
	rl_replace_line("", 1);
#endif
#if 0	// COMPILE ERROR
	rl_redisplay();
#endif
	g_minishell.is_ended = 1;
	g_minishell.state = 1;
}
