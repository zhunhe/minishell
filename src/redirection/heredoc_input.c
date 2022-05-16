#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include "../includehena/test.h"
#include "../includehena/pipe_signal.h"
// #include <minishell.h>
#define TRUE 1
#define FALSE 0

/*ft_strlen,  ft_strcmp 있어야함 */
extern t_minishell g_minishell;

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
			write(fd, "\n", 1);
		else if (!strcmp(str, end)) // ft_strcmp로 고쳐야함
		{
			free(str);
			break ;
		}
		else
		{
			write(fd, str, strlen(str)); // < ft_strlen으로 고치기
			write(fd, "\n", 1);
		}
		free(str);
	}
}

/*
*	heredoc 하나씩 실행할 예정
*	히어독 안에 환경변수 보류하기
*	signal 처리 및 echoctl_off처리 후 heredoc시작
*/

static void	change_prompt_option()
{
	signal(SIGINT, sig_heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
	echoctl_off();
}

int	run_heredoc(t_list *heredoc)
{
	t_heredoc	*iter;
	int			fd;

	iter = (t_heredoc *)heredoc;
	change_prompt_option();
	while (iter->next)
	{
		iter = iter->next;
		fd = open(iter->file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (fd < 0)
		{
			g_minishell.is_ended = 1;
			return (FALSE);
		}
		heredoc_prompt(fd, iter->end_string);
	}
	return (TRUE);
}
