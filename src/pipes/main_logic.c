/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:42:51 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 20:26:58 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "minishell.h"
#include "redirect.h"
#include "main_logic.h"
#include "pipe_signal.h"
#define TRUE 1
#define FALSE 0

void	start_setting(void)
{
	signal(SIGINT, sig_cmd_int_handler);
	signal(SIGQUIT, sig_cmd_quit_handler);
	echoctl_on();
}

void	end_setting(void)
{
	dup2(254, 0);
	dup2(255, 1);
	close(254);
	close(255);
}

static void	pipe_logic(t_list *parse, t_list *heredoc)
{
	t_exec	*execl;

	execl = (t_exec *)parse->data;
	dup2(0, 254);
	dup2(1, 255);
	if (!parse->next)
		tree_traversal(execl->root, execl, 0, heredoc);
	else
		fork_pipe(parse, heredoc);
}

void	main_logic(t_list *exec, t_list *heredoc)
{
	if (!run_heredoc(heredoc))
		return ;
	start_setting();
	pipe_logic(exec, heredoc);
}
