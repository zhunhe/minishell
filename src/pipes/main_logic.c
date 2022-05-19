/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:42:51 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 00:35:39 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "redirect.h"
#include <signal.h>
#include <unistd.h>
#include "main_logic.h"
#include "pipe_signal.h"
#include "heredoc_input.h"
#define TRUE 1
#define FALSE 0

static void	start_setting(void)
{
	signal(SIGINT, sig_cmd_int_handler);
	signal(SIGQUIT, sig_cmd_quit_handler);
	echoctl_on();
}

static void	end_setting(void)
{
	close(254);
	close(255);
}

static void	pipe_logic(t_list *parse)
{
	t_exec	*execl;

	execl = (t_exec *)parse->data;
	if (!parse->next)
	{
		dup2(0, 254);
		dup2(0, 255);
		tree_traversal(execl->root, execl, 0);
		dup2(254, 0);
		dup2(255, 1);
	}
	else
		fork_pipe(parse);
}

int	main_logic(void)
{
	t_list	*heredoc;
	t_list	*exec;

	heredoc = g_minishell.heredoc;
	if (!run_heredoc(heredoc))
		return (FALSE);
	start_setting();
	exec = g_minishell.exec;
	pipe_logic(exec);
	end_setting();
	return (TRUE);
}
