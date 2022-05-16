#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //// TODO:: 헤더 삭제 해야함.
#include "minishell.h"
#include "parse.h"
#include "built_in.h"
#include "redirect.h"

extern t_minishell g_minishell;

// COMPILE ERROR
static void	excute_alone_cmd(t_exec *data)
{
	int	pid;
	int state;

	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
		execve(data->cmd_path, data->cmd_argv, get_envp_double_pointer()); // TODO:: envp 2차원 배열로 넣어줘야하므로 NULL로 일단 대체
	else
	{
		wait(&state);
		g_minishell.state = state;
	}
}


// COMPILE ERROR
//TODO:: 나중에 strcmp를 ft_strcmp로 고치고 헤더 추가해야 함
static void	select_cmd(t_exec *data)
{
	// if (!ft_strcmp(data->argv[0], "cd"))
	// 	ft_cd(data);
	// else if (!ft_strcmp(data->argv[0], "cd"))
	// 	ft_cd(data);
	// else if (!ft_strcmp(data->argv[0], "cd"))
	// 	ft_cd(data, 0);
	// if (!strcmp(data->cmd, "echo"))
	// 	ft_echo(data, 1);
	// else if (!strcmp(data->cmd, "env"))
	// 	ft_env(data, 0);
	// else if (!strcmp(data->cmd, "pwd"))
	// 	ft_pwd(data, 0);
	// else if (!strcmp(data->cmd, "unset"))
	// 	ft_unset(data, 0);
	// else
		excute_alone_cmd(data);
}

// COMPILE ERROR
//TODO:: 나중에 strcmp를 ft_strcmp로 고치고 헤더 추가해야 함
static void	select_multiple_cmd(t_exec *data)
{
	// if (!ft_strcmp(data->cmd, "cd"))
	// 	ft_cd(data);
	// else if (!ft_strcmp(data->cmd, "cd"))
	// 	ft_cd(data);
	// else if (!ft_strcmp(data->cmd, "cd"))
	// 	ft_cd(data, 0);
	// if (!strcmp(data->cmd, "echo"))
	// 	ft_echo(data, 1);
	// else if (!strcmp(data->cmd, "env"))
	// 	ft_env(data, 1);
	// else if (!strcmp(data->cmd, "pwd"))
	// 	ft_pwd(data, 1);
	// else if (!strcmp(data->cmd, "unset"))
	// 	ft_unset(data, 1);
	// else
		execve(data->cmd_path, data->cmd_argv, get_envp_double_pointer());//g_minishell.envp이 아닌 2차원 배열 필요
}

void	tree_traversal_alone(t_node *tree, t_exec *data, int type)
{
	if (!tree)
		return ;
	if (tree->type == TYPE_IN_OVERWRITE) //  <
		input(tree->right->file_name, 0);
	else if (tree->type == TYPE_OUT_OVERWRITE) // >
		output(tree->right->file_name, 1);
	// else if (tree->type == TYPE_HEREDOC) // <<
	else if (tree->type == TYPE_OUT_APPEND) // >>
		output_append(tree->right->file_name, 1);
	else if (tree->type == TYPE_CMD)
	{
		if (!type)
			select_cmd(data);
		else
			select_multiple_cmd(data);
	}
	tree_traversal_alone(tree->left, data, type);
}
