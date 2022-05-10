/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:32:02 by juhur             #+#    #+#             */
/*   Updated: 2022/05/10 17:27:57 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <list.h>
# include <ast.h>

typedef struct s_token
{
	t_node_type	type;
	char		*data;
}	t_token;

typedef struct s_envp
{
	char	*key;
	char	*value;
}	t_envp;

typedef enum e_status
{
	STATUS_OK,
	STATUS_ERROR_INVALID_CHAR,
	STATUS_ERROR_QUOTES_OPENED,
	STATUS_MAX
}	t_status;

typedef struct s_minishell
{
	t_list		*envp;
	t_status	status;
	t_list		*exec;
}	t_minishell;

extern t_minishell	g_minishell;

# define MINISHELL	"\e[01;32mminishell$ \e[0m"

# define KEY		0
# define VALUE		1

/*
** prompt.c
*/
void		print_prompt(void);

/*
** echoctl.c
*/
void		echoctl_on(void);
void		echoctl_off(void);

/*
** parse.c
*/
t_status	parse(char *s);

/*
** envp.c
*/
void		set_envp(char **envp);
char		**get_envp_double_pointer(void);

/*
** error.c
*/
t_status	check_error(char *s);
void		malloc_error(void);

/*
** tokenize.c
*/
t_list		*tokenize(char *s);
void		remove_token(void *arg);
#endif