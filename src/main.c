/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:58:28 by juhur             #+#    #+#             */
/*   Updated: 2022/04/06 19:47:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <termios.h>

void sig_handler(int signal)
{
	if (signal == SIGINT)
		printf("minishell$ \n");

	if (rl_on_new_line() == -1) // readline으로 설정한 문자열을 한 번 출력한다?
		exit(1);
	rl_replace_line("", 1); // 프롬프트에 이미 친 문자열을 싹 날려준다.
	rl_redisplay();         // 프롬프트 커서가 움직이지 않게 해준다.
}

void setting_signal()
{
	signal(SIGINT, sig_handler); // CTRL + C
	signal(SIGQUIT, SIG_IGN);    // CTRL + /
								 // signal(SIGTERM, sig_handler);
}

int main(void)
{
	char			*str;
	struct termios	term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	setting_signal();

	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
		{
			printf("\033[1A");
			printf("\033[10C");
			printf(" exit\n");
			exit(-1);
		}
		else if (*str == '\0')
			free(str);
		else
		{
			add_history(str);
			printf("%s\n", str);
			free(str);
		}
	}
	return (0);
}
