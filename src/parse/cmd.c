/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:40:02 by juhur             #+#    #+#             */
/*   Updated: 2022/05/18 17:14:14 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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
	char	**path_value;
	int		i;

	if (is_builtin(cmd))
		return (NULL);
	path_value = _split(get_envp_value("PATH"), ':');
	i = -1;
	while (path_value[++i] != NULL)
	{
		path = _strdup(path_value[i]);
		path = _strjoin_free(path, "/");
		path = _strjoin_free(path, cmd);
		fd = open(path, O_RDONLY);
		close(fd);
		if (fd > 2)
			return (path);
		free(path);
	}
	return (NULL);
}

t_node	*set_cmd(t_exec *result, char *s)
{
	t_node	*cmd_node;
	char	**ss;

	ss = _split(s, ' ');
	cmd_node = create_node(_strdup(ss[0]));
	cmd_node->type = TYPE_CMD;
	result->cmd = _strdup(ss[0]);
	result->cmd_path = get_cmd_path(ss[0]);
	// TODO: splitted된 char **ss를 _strjoin을 이용해 붙여주는 작업 필요함. {"CMD", "-n(option)", "-n(option)", "string"}
	// result->cmd_argv =
	_split_free(ss);
	return (cmd_node);
}
