/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:31:28 by juhur             #+#    #+#             */
/*   Updated: 2022/05/15 21:00:12 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdbool.h>
# include "list.h"

typedef enum e_node_type
{
	TYPE_IN_OVERWRITE,
	TYPE_OUT_OVERWRITE,
	TYPE_HEREDOC,
	TYPE_OUT_APPEND,
	TYPE_CMD,
	TYPE_ETC
}	t_node_type;

typedef struct s_node
{
	t_node_type		type;
	char			*file_name;
	int				heredoc_idx;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_exec
{
	int		pid;
	int		fd;
	char	*cmd;
	char	*cmd_path;
	char	**cmd_argv;
	bool	heredoc;
	bool	pipe_exist;
	t_node	*root;
}	t_exec;

/*
** parse.c
*/
t_node_type	get_type(char *str);

/*
** exec.c
*/
t_exec		*make_exec(t_list *token, int *status, int *heredoc_idx);

/*
** tokenize.c
*/
t_list		*tokenize(char *s);

/*
** ast.c
*/
t_node		*create_node(char *data);
void		add_node_root(t_node **root, t_node *new);
void		add_node_right(t_node **parent, t_node *child);
#endif