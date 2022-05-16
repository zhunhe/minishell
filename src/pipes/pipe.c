/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "parse.h"

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
	// printf("%d %d %d\n", pid, wpid, status);
}

void	fork_pipe(t_list *link, char **envp)
{
	int	p[2];
	t_list	*head;
	t_exec	*exec;
	int		last_pid;

	head = link;
	while (link)
	{
		pipe(p);
		exec = (t_exec *)link->data;
		exec->pid = fork();
		// printf("pid[%d]\n", exec->pid);				//각 노드별로 pid체크 용도 test 
		if (exec->pid < 0)
			exit(0);
		else if (exec->pid > 0)
			change_connection_pipe_parent(link, p);
		else
		{
			change_connection_pipe_child(link, p);
			// TODO:: execve 대신 트리 순회로 바꿔야 함.
			execve(exec->cmd_address, exec->argv, envp);// TODO:: 트리 순회 필요할 듯
		}
		if (link->next)
			((t_exec *)link->next->data)->fd = 3;
		link = link->next;
		last_pid = exec->pid;
	}
	close(3);
	wait_all_child(head, last_pid);
}
*/