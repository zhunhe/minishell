#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "parse.h"
#include "main_logic.h"

extern t_minishell g_minishell;

void	change_connection_pipe_parent(t_list *cmd, int *p)
{
	t_exec	*exec;

	exec = (t_exec *)cmd->data;
	close(p[1]); 					// write close
	if (exec->fd != 0)
	{
		dup2(p[0], 3);
		close(p[0]);
	}
}

void	change_connection_pipe_child(t_list *cmd, int *p)
{
	t_exec	*exec;

	exec = (t_exec *)cmd->data;
	close(p[0]); 					// read close 현재꺼 닫기	
	if (cmd->next)
		dup2(p[1], 1);
	close(p[1]);
	if (exec->fd)
	{
		dup2(exec->fd, 0);
		close(exec->fd);
	}
}

void	wait_all_child(t_list *head, int last_pid)
{
	int	pid;
	int state;

	while (head)
	{
		pid = wait(&state);
		if (pid == last_pid)
			g_minishell.state = state; //TODO 전역변수랑 연결, 값 확인 필요
		head = head->next;
	}
}

void	fork_pipe(t_list *link)
{
	int	p[2];
	t_list	*head;
	t_exec	*exec;

	head = link;
	while (link)
	{
		pipe(p);
		exec = (t_exec *)link->data;
		exec->pid = fork();
		if (exec->pid < 0)
			exit(1);
		else if (exec->pid > 0)
			change_connection_pipe_parent(link, p);
		else
		{
			change_connection_pipe_child(link, p);
			tree_traversal_alone(exec->root, exec, 1);
		}
		if (link->next)
			((t_exec *)link->next->data)->fd = 3;
		link = link->next;
	}
	close(3);
	wait_all_child(head, exec->pid);
}