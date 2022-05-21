/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:39:49 by hena              #+#    #+#             */
/*   Updated: 2022/05/21 19:19:52 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "built_in.h"
#include "redirect.h"
#include "util.h"
#include "main_logic.h"

static void	execve_error_print(char *str, int pipe_exist, char **envp)
{
	_putstr_fd("bash: ", 2);
	_putstr_fd(str, 2);
	_putendl_fd(": command not found", 2);
	envp = 0;	//TODO free넣어줘야할 부분
	g_minishell.exit_status = 127;
	if (pipe_exist)
		exit (127);
}

static void	excute_alone_cmd(t_exec *data)
{
	char	**envp;
	int		pid;
	int		exit_status;

	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		envp = get_envp_double_pointer();
		if (execve(data->cmd_path, data->cmd_argv, \
		envp))
			execve_error_print(data->cmd, 0, envp);
	}
	else
	{
		wait(&exit_status);
		g_minishell.exit_status = set_exit_status(exit_status);
	}
}

/*
 *	no pipe, built-in [pwd exit echo env unset export cd], execve
 */

static void	select_cmd(t_exec *data)
{
	if (!_strcmp(data->cmd, "pwd"))
		ft_pwd(data, 0);
	else if (!_strcmp(data->cmd, "exit"))
		ft_exit(data, 0);
	else if (!_strcmp(data->cmd, "echo"))
		ft_echo(data, 0);
	else if (!_strcmp(data->cmd, "env"))
		ft_env(data, 0);
	else if (!_strcmp(data->cmd, "unset"))
		ft_unset(data, 0);
	else if (!_strcmp(data->cmd, "export"))
		ft_export(data, 0);
	else if (!_strcmp(data->cmd, "cd"))
		ft_cd(data, 0);
	else
		excute_alone_cmd(data);
}

/*
 *	pipes exist, built-in [pwd exit echo env unset export cd]
 */

static void	select_multiple_cmd(t_exec *data)
{
	char	**envp;

	if (!_strcmp(data->cmd, "pwd"))
		ft_pwd(data, 1);
	else if (!_strcmp(data->cmd, "exit"))
		ft_exit(data, 1);
	else if (!_strcmp(data->cmd, "echo"))
		ft_echo(data, 1);
	else if (!_strcmp(data->cmd, "env"))
		ft_env(data, 1);
	else if (!_strcmp(data->cmd, "unset"))
		ft_unset(data, 1);
	else if (!_strcmp(data->cmd, "export"))
		ft_export(data, 1);
	else if (!_strcmp(data->cmd, "cd"))
		ft_cd(data, 1);
	else
	{
		envp = get_envp_double_pointer();
		if (execve(data->cmd_path, data->cmd_argv, \
		envp))
			execve_error_print(data->cmd, 1, envp);
	}
}

void	tree_traversal(t_node *tree, t_exec *data, \
int pipe_exist, t_list *heredoc)
{
	if (!tree)
	{
		end_setting();
		return ;
	}
	if (tree->type == TYPE_IN_OVERWRITE)
		input(tree->right->file_name, 0);
	else if (tree->type == TYPE_OUT_OVERWRITE)
		output(tree->right->file_name, 1);
	else if (tree->type == TYPE_HEREDOC)
		here_doc(tree->right->heredoc_idx, 0, heredoc);
	else if (tree->type == TYPE_OUT_APPEND)
		output_append(tree->right->file_name, 1);
	else if (tree->type == TYPE_CMD)
	{
		if (!pipe_exist)
			select_cmd(data);
		else
			select_multiple_cmd(data);
	}
	tree_traversal(tree->left, data, pipe_exist, heredoc);
}
