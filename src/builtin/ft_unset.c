/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:44:14 by hena              #+#    #+#             */
/*   Updated: 2022/05/16 16:00:52 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../includehena/check_string_util.h"
#include "minishell.h"
#include "parse.h"
#include <string.h> //TODO:: 삭제해야 함
#ifndef BOOL
# define BOOL

# define TRUE 1
# define FALSE 0

#endif


// extern t_minishell g_minishell;

// COMPILE ERROR
static void	find_and_erase_key(char *str)
{
	t_list	*envpl;
	t_list	*prev;
	t_envp	*envp;

	envpl = g_minishell.envp->next;	// 전역 필요
	prev = g_minishell.envp;		//전역 필요
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
	// COMPILE ERROR
		if (!ft_strcmp(envp->key, str))
		{
			prev->next = envpl->next;
			free(envp->key);
			free(envp->value);
			free(envp);
			free(envpl);//TODO:: leak 체크 해야할듯
			break ;
		}

		envpl = envpl->next;
		prev = prev->next;
	}
}


// COMPILE ERROR
static int	is_valid_idenfier(char *str)
{
	if (!((is_small_alpha(*str) || is_big_alpha(*str) || *str == '_')))
		return (FALSE);
	while (*str)
	{
// COMPILE ERROR
		if (!((is_small_alpha(*str) || is_big_alpha(*str) || \
		is_integer(*str) || *str == '_')))
			return (FALSE);

		str++;
	}
	return (TRUE);
}


// COMPILE ERROR
static void	unset_error_print(char *argv)
{
// COMPILE ERROR
	write(2, "unset: `", 8);

// COMPILE ERROR
	write(2, *argv, strlen(*argv)); //TODO:: strlen ->ft_strlen

// COMPILE ERROR
	write(2, "': not a valid identifier\n", 26);

}


// COMPILE ERROR
void	ft_unset(t_exec	*data, int pipe_flag)
{
	int		err_flag;
	char	**argv;

	err_flag = 0;
	argv++;
	while (*argv)
	{
		if (!is_valid_idenfier(*argv))
		{
// COMPILE ERROR
			unset_error_print(*argv);

			err_flag = 1;
		}
	// COMPILE ERROR
		else
			find_and_erase_key(*argv);

		argv++;
	}
	g_minishell.state = 0;
// COMPILE ERROR
	if (pipe_flag)
		exit(0);

}
*/