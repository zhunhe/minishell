/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:39:49 by hena              #+#    #+#             */
/*   Updated: 2022/05/18 04:39:52 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //// TODO:: 헤더 삭제 해야함.
#include "minishell.h"
#include "parse.h"
#include "built_in.h"
#include "redirect.h"
#include "util.h"

extern t_minishell	g_minishell;

static void	excute_alone_cmd(t_exec *data)
{
	int	pid;
	int	state;

	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
		execve(data->cmd_path, data->cmd_argv,
			get_envp_double_pointer());
	else
	{
		wait(&state);
		g_minishell.state = state;
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
	if (!strcmp(data->cmd, "pwd"))
		ft_pwd(data, 1);
	else if (!strcmp(data->cmd, "exit"))
		ft_exit(data, 1);
	else if (!strcmp(data->cmd, "echo"))
		ft_echo(data, 1);
	else if (!strcmp(data->cmd, "env"))
		ft_env(data, 1);
	else if (!strcmp(data->cmd, "unset"))
		ft_unset(data, 1);
	else if (!strcmp(data->cmd, "export"))
		ft_export(data, 1);
	else if (!strcmp(data->cmd, "cd"))
		ft_cd(data, 1);
	else
		execve(data->cmd_path, data->cmd_argv,
			get_envp_double_pointer());
}

void	tree_traversal_alone(t_node *tree, t_exec *data, int type)
{
	if (!tree)
		return ;
	if (tree->type == TYPE_IN_OVERWRITE)
		input(tree->right->file_name, 0);
	else if (tree->type == TYPE_OUT_OVERWRITE)
		output(tree->right->file_name, 1);
	// else if (tree->type == TYPE_HEREDOC)
	// 	here_doc(tree->right->heredoc_idx, 0);
	else if (tree->type == TYPE_OUT_APPEND)
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
