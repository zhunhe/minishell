/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:48:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/13 05:16:14 by juhur            ###   ########.fr       */
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

static void	print_error_msg(t_status status)
{
	const char	*msg[STATUS_MAX] = {
		"",
		"Error! There is invalid char '\\' or ';'\n",
		"Error! Quotes is not closed\n",
		"minishell: syntax error near unexpected token\n"
	};

	if (status != STATUS_OK)
		printf("%s", msg[status]);
}

static void	exit_minishell(void)
{
	printf("\e[1A\e[10C exit\n");
	exit(0);
}

void	print_prompt(void)
{
	char		*str;
	t_status	status;

	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		status = STATUS_OK;
		str = readline(MINISHELL);
		if (str == NULL)
			exit_minishell();
		else if (*str != '\0')
		{
			if (parse(str, &status) == ERROR)
				print_error_msg(status);
			else
			{
				add_history(str);
				// 실행함수위치
			}
		}
		free(str);
	}
}
