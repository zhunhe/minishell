/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:31:28 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 14:22:06 by juhur            ###   ########.fr       */
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

typedef struct s_heredoc
{
	char	*end_string;
	char	*file_name;
}	t_heredoc;

/*
** parse.c
*/
t_node_type	get_type(char *str);

/*
** exec.c
*/
t_exec		*make_exec(t_list *token, int *heredoc_idx, int *status);

/*
** tokenize.c
*/
t_list		*tokenize(char *s);

/*
** ast.c
*/
t_node		*create_node(char *data);
void		remove_ast(t_node *node);
void		add_left_leaf_to_child(t_node **root, t_node *child, bool left);

/*
** cmd.c
*/
t_node		*set_cmd(t_exec *result, char *s);

/*
** heredoc.c
*/
t_list		*get_heredoc(t_list *exec);

/*
** free.c
*/
void		free_token(t_list **token);
void		free_lists(t_list **heredoc, t_list **exec);

/*
** interpret.c
*/
char		*interpret(char *line);

/*
** remover.c
*/
void		data_remover(void *ptr);
void		heredoc_remover(void *ptr);
void		node_remover(void *ptr);
void		exec_remover(void *ptr);
#endif