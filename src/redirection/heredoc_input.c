/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:54:20 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 00:26:16 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "parse.h"
#include "pipe_signal.h"
#include "util.h"

#define TRUE 1
#define FALSE 0

static void	heredoc_prompt(int fd, char *end)
{
	char	*str;

	while (1)
	{
		str = readline(">");
		if (str == NULL)
		{
			close(fd);
			break ;
		}
		else if (*str == '\0')
			_putendl_fd("", fd);
		else if (!_strcmp(str, end))
		{
			free(str);
			break ;
		}
		else
			_putendl_fd(str, fd);
		free(str);
	}
}

static void	change_prompt_to_heredoc_option(void)
{
	signal(SIGINT, sig_heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
	echoctl_off();
}

int	run_heredoc(t_list *iter)
{
	t_heredoc	*h_iter;
	int			fd;

	change_prompt_to_heredoc_option();
	while (iter)
	{
		h_iter = (t_heredoc *)iter->data;
		printf("[%s]\n", h_iter->file_name);
		fd = open(h_iter->file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (fd < 0)
		{
			_putendl_fd("can't open file", 2);
			return (FALSE);
		}
		heredoc_prompt(fd, h_iter->end_string);
		close(fd);
		iter = iter->next;
	}
	return (TRUE);
}
