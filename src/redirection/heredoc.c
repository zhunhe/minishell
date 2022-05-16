#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../includehena/test.h"

extern t_minishell g_minishell;

void	here_doc(int index, int dup_fd)
{
	t_heredoc	*iter;
	int			fd;
	int			i;

	i = -1;
	iter = (t_heredoc *)g_minishell.heredoc;
	while (++i < index)
		iter = iter->next;
	fd = open(iter->file_name, O_RDWR, 0644);
	if (fd < 0)
		exit(1);
	dup2(fd, dup_fd);
	close(fd);
}
