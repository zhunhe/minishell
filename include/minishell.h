/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:32:02 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 14:25:43 by juhur            ###   ########.fr       */
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
	STATUS_NONE,
	STATUS_ERROR_INVALID_CHAR,
	STATUS_ERROR_QUOTES_OPENED,
	STATUS_SYNTAX_ERROR,
	STATUS_HEREDOC_COUNT_ERROR,
	STATUS_MAX
}	t_status;

typedef struct s_minishell
{
	t_list		*envp;
	int			exit_status;
	char		*oldpwd;
	int			signal;
}	t_minishell;

t_minishell	g_minishell;

# define MINISHELL	"minishell$ "

# define KEY		0
# define VALUE		1

# define OK			0
# define ERROR		1

/*
** prompt.c
*/
bool		print_prompt(void);

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
char		*get_envp_value(char *key);

/*
** error.c
*/
bool		check_error(char *s, int *status);

#endif