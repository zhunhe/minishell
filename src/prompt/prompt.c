/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:48:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/12 23:14:19 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <minishell.h>

static void	sig_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	printf("%s\n", MINISHELL);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	print_error_msg(void)
{
	const char	*msg[STATUS_MAX] = {
		"",
		"Error! There is invalid char '\' or ';'\n",
		"Error! Quotes is not closed\n",
		"minishell: syntax error near unexpected token\n"
	};

	if (g_minishell.status != STATUS_OK)
		printf("%s", msg[g_minishell.status]);
	g_minishell.status = STATUS_OK;
}

void	print_prompt(void)
{
	char	*str;

	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str = readline(MINISHELL);
		if (str == NULL)
		{
			printf("\e[1A\e[10C exit\n");
			exit(-1);
		}
		else if (*str == '\0')
			free(str);
		else
		{
			if (parse(str) == STATUS_OK)
				add_history(str);
			else
				print_error_msg();
			free(str);
		}
	}
}
