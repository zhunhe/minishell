/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:48:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 09:52:03 by hena             ###   ########.fr       */
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
		"Error! There is invalid char '\\' or ';'\n",
		"Error! Quotes is not closed\n",
		"minishell: syntax error near unexpected token\n",
		"minishell: maximum here-document count exceeded\n"
	};

	if (status != STATUS_OK)
		printf("%s", msg[status]);
}

static void	exit_minishell(void)
{
	printf("\e[1A\e[10C exit\n");
	printf("[%s %d]\n", __FUNCTION__, __LINE__);
	exit(0);
}

static void	init_prompt(int *status)
{
	echoctl_off();
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	*status = STATUS_OK;
}

void	print_prompt(void)
{
	char		*str;
	int			status;
	t_list		*exec;
	t_list		*heredoc;

	while (1)
	{
		init_prompt(&status);
		printf("[%s %d]\n", __FUNCTION__, __LINE__);
		str = readline(MINISHELL);
		printf("[%s %d]\n", __FUNCTION__, __LINE__);
		if (str == NULL)
			exit_minishell();
		else if (*str != '\0')
		{
			exec = parse(str, &status);
			if (status == STATUS_OK)
			{	
				heredoc = get_heredoc(exec);	
			}
			if (status == STATUS_OK)
			{
				add_history(str);
				// printf("[%s %d]\n", __FUNCTION__, __LINE__);
				main_logic(exec, heredoc);
				printf("[%s %d]\n", __FUNCTION__, __LINE__);
				unlink_all(heredoc);
				g_minishell.signal = 0;
			}
			else
				print_error_msg(status);
		}
		_free((void **)&str);
	}
}
