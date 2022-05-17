/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:42:51 by hena              #+#    #+#             */
/*   Updated: 2022/05/12 02:42:53 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "redirect.h"
#include <signal.h>
#include <unistd.h>
#include "main_logic.h"
#include "pipe_signal.h"
#define TRUE 1
#define FALSE 0

extern t_minishell	g_minishell;

static void	start_setting(void)
{
	sig_cmd_int_handler(SIGQUIT);
	sig_cmd_quit_handler(SIGQUIT);
	dup2(0, 254);
	dup2(0, 255);
}

static void	end_setting(void)
{
	dup2(254, 0);
	dup2(255, 1);
	close(254);
	close(255);
}

static void	pipe_logic(t_list *parse)
{
	t_exec	*execl;

	execl = (t_exec *)parse->data;
	if (!parse->next)
	{
		start_setting();
		tree_traversal_alone(execl->root, execl, 0);
		end_setting();
	}
	else
		fork_pipe(parse);
}

int	main_logic()
{
	// t_list	*heredoc;
	t_list	*exec;

	sig_heredoc_handler(SIGINT);
	// heredoc = g_minishell.heredoc;
	// readline 인클루드 못해서 확인 불가	TODO:: 확인해야 함
	// if (!run_heredoc(heredoc)) 		// heredoc 실패 시 종료임 아니면 내가 말고?. free해줄지 체크
	// 	return (FALSE);
	start_setting();
	exec = g_minishell.exec;
	pipe_logic(exec);
	end_setting();
	return (TRUE);
}
