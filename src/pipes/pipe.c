#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../includehena/test.h"

#if 0
typedef struct s_list
{
	struct s_list  *next;
	void           *data;
} t_list;

int status;
typedef struct link
{
	int     pid;          // 0
	int    fd;           // 0
	char   *cmd;         // "echo"
	char    *cmd_address; // "/bin/ls"
	char    **argv;       // {"echo", ("option"), ("arg"), ("arg"), NULL}
	//tree 필요
}				t_exec;
#endif

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

/*
 * 다시 생각해야할 듯
 */
void	wait_all_child(t_list *head, int last_pid)
{
	int	pid;
#if 0	// COMPILE ERROR
	int tmp;
#endif
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

#if 0 // test용도 코드
t_list *init_link()
{
	t_list *cmd;
	
	cmd = (t_list *)malloc(sizeof(t_list));
	cmd->next = NULL;
	cmd->data = NULL;
	return cmd;
}

t_exec *init_exec()
{
	t_exec *cmd;
	
	cmd = (t_exec *)malloc(sizeof(t_exec));
	cmd->cmd = NULL;
	cmd->cmd_address = NULL;
	cmd->fd = 0;
	cmd->pid = 0;
	return cmd;
}


int main(int argc, char **argv, char **envp)
{
	t_list *new;
	t_list *head;
	t_exec *data;

	new = init_link();
	head = new;
	data = init_exec();
	// printf("%s %s", head->data, head->next);
	new->data = (void *)data;
	data->cmd = strdup("cat");
	data->cmd_address = strdup("/bin/cat");
	data->argv = (char **)malloc(sizeof(char *) * 3);
	data->argv[0] = strdup("cat");
	data->argv[1] = NULL;

	
	
	new = init_link();
	
	data = init_exec();
	new->data = (void *)data;
	data->cmd = strdup("ls");
	data->cmd_address = strdup("/bin/ls");

	data->argv = (char **)malloc(sizeof(char *) * 3);
	data->argv[0] = strdup("ls");
	data->argv[1] = NULL;
	head->next = new;	

	fork_pipe(head, envp); // g_minishell envp가져와야 할듯? 2차원 배열
}
#endif