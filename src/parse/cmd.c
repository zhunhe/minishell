/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:40:02 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 12:52:19 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <minishell.h>
#include <parse.h>
#include <util.h>

static bool	is_builtin(char *cmd)
{
	if (!_strcmp(cmd, "echo")
		|| !_strcmp(cmd, "cd")
		|| !_strcmp(cmd, "pwd")
		|| !_strcmp(cmd, "export")
		|| !_strcmp(cmd, "unset")
		|| !_strcmp(cmd, "env")
		|| !_strcmp(cmd, "exit"))
		return (true);
	return (false);
}

static char	*get_cmd_path(char *cmd)
{
	char	*path;
	int		fd;
	char	**path_list;
	int		i;

	if (is_builtin(cmd))
		return (NULL);
	path_list = _split(get_envp_value("PATH"), ':');
	if (path_list == NULL)
		return (NULL);
	i = -1;
	while (path_list[++i] != NULL)
	{
		path = _strdup(path_list[i]);
		path = _strjoin_free(path, "/", false);
		path = _strjoin_free(path, cmd, false);
		fd = open(path, O_RDONLY);
		if (fd > 2)
		{
			close(fd);
			_free_double_pointer((void ***)&path_list);
			return (path);
		}
		_free((void **)&path);
	}
	_free_double_pointer((void ***)&path_list);
	return (_strdup(cmd));
}

char	**get_cmd_argv(char **ss)
{
	char	**cmd_argv;
	int		count;
	int		i;

	count = 0;
	while (ss[count] != NULL)
		++count;
	cmd_argv = _calloc(count + 1, sizeof(char *));
	i = -1;
	while (++i < count)
		cmd_argv[i] = interpret(ss[i]);
	return (cmd_argv);
}

t_node	*set_cmd(t_exec *result, char *s)
{
	t_node	*cmd_node;
	char	**ss;

	ss = _split(s, ' ');
	cmd_node = create_node(_strdup(ss[0]));
	if (cmd_node->type != TYPE_ETC)
	{
		_free_double_pointer((void ***)&ss);
		_free((void **)&cmd_node);
		return (NULL);
	}
	cmd_node->type = TYPE_CMD;
	result->cmd = interpret(ss[0]);
	result->cmd_path = get_cmd_path(result->cmd);
	result->cmd_argv = get_cmd_argv(ss);
	_free_double_pointer((void ***)&ss);
	return (cmd_node);
}
