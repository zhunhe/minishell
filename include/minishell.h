/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:32:02 by juhur             #+#    #+#             */
/*   Updated: 2022/05/14 21:27:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdbool.h>
# include "list.h"

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
	STATUS_SYNTAX_ERROR,
	STATUS_MAX
}	t_status;

typedef struct s_minishell
{
	t_list		*envp;
	t_list		*exec;
	int			state;
	char		*oldpwd;
}	t_minishell;

t_minishell	g_minishell;

# define MINISHELL	"\e[01;32mminishell$ \e[0m"

# define KEY		0
# define VALUE		1

# define OK			0
# define ERROR		1

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
t_list		*parse(char *s, int *status);

/*
** envp.c
*/
void		set_envp(char **envp);
char		**get_envp_double_pointer(void);

/*
** error.c
*/
bool		check_error(char *s, int *status);
void		malloc_error(void);

#endif