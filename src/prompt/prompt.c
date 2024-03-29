/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:48:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 16:16:30 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <minishell.h>
#include <parse.h>
#include <list.h>
#include <util.h>
#include "main_logic.h"
#include "built_in.h"

static void	sig_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	g_minishell.exit_status = 1;
	printf("%s\n", MINISHELL);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	print_error_msg(t_status status)
{
	const char	*msg[STATUS_MAX] = {
		"",
		"",
		"Error! There is invalid char '\\' or ';'\n",
		"Error! Quotes is not closed\n",
		"minishell: syntax error near unexpected token\n",
		"minishell: maximum here-document count exceeded\n"
	};

	if (status != STATUS_OK)
		printf("%s", msg[status]);
	if (status == STATUS_HEREDOC_COUNT_ERROR)
		exit(2);
}

static void	init_prompt(int *status, t_list **exec, t_list **heredoc)
{
	echoctl_off();
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	*status = STATUS_OK;
	*exec = NULL;
	*heredoc = NULL;
	g_minishell.signal = 0;
}

bool	print_prompt(void)
{
	char		*str;
	int			status;
	t_list		*exec;
	t_list		*heredoc;

	init_prompt(&status, &exec, &heredoc);
	str = readline(MINISHELL);
	if (str == NULL)
		return (false);
	else if (*str != '\0')
	{
		exec = parse(str, &status);
		if (status == STATUS_OK)
		{
			heredoc = get_heredoc(exec);
			add_history(str);
			main_logic(exec, heredoc);
			unlink_all(heredoc);
		}
		else
			print_error_msg(status);
		free_lists(&heredoc, &exec);
	}
	_free((void **)&str);
	return (true);
}
