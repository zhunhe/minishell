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

#include "check_string_util.h"
#include "minishell.h"
#include "parse.h"
#include <stdlib.h>
#include <string.h> //TODO:: 삭제해야 함
#include <unistd.h>
#ifndef BOOL
# define BOOL

# define TRUE 1
# define FALSE 0

#endif

extern t_minishell g_minishell;

// COMPILE ERROR

void	free_list(t_list	**list)
{
	t_envp	*envp;

	envp = (*list)->data;
	free(envp->key);
	free(envp->value);
	envp->key = NULL;
	envp->value = NULL;
	free(envp);
	envp = NULL;
	free(*list);
	list = NULL;
}

static void	find_and_erase_key(char *str)
{
	t_list	*envpl;
	t_list	*prev;
	t_envp	*envp;

	envpl = g_minishell.envp;
	envp = (t_envp *)envpl->data;
	if (!strcmp(envp->key, str))
	{
		g_minishell.envp = envpl->next;
		free_list(&envpl);
		return ;
	}
	prev = envpl;
	envpl = envpl->next;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!strcmp(envp->key, str))
		{
			prev->next = envpl->next;
			free_list(&envpl);
			break ;
		}
		envpl = envpl->next;
		prev = prev->next;
	}
}

static int	is_valid_idenfier(char *str)
{
	if (!((is_small_alpha(*str) || is_big_alpha(*str) || *str == '_')))
		return (FALSE);
	while (*str)
	{
		if (!((is_small_alpha(*str) || is_big_alpha(*str) || \
		is_digit(*str) || *str == '_')))
			return (FALSE);

		str++;
	}
	return (TRUE);
}


static void	unset_error_print(char *argv)
{
	write(2, "unset: `", 8);
	write(2, argv, strlen(argv)); //TODO:: strlen ->ft_strlen
	write(2, "': not a valid identifier\n", 26);
}

void	ft_unset(t_exec	*data, int pipe_flag)
{
	int		err_flag;
	char	**argv;

	argv = data->cmd_argv;
	err_flag = 0;
	argv++;
	while (*argv)
	{
		if (!is_valid_idenfier(*argv))
		{
			unset_error_print(*argv);
			err_flag = 1;
		}
		else
			find_and_erase_key(*argv);
		argv++;
	}
	g_minishell.state = 0;
	if (pipe_flag)
		exit(0);
}

#if 0
t_list *create_l()
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = 0;
	new->next = 0;
	return (new);
}

t_envp *create_e(char *key, char *value)
{
	t_envp	*new;

	new = (t_envp *)malloc(sizeof(t_envp));
	if (key)
		new->key = strdup(key);
	else
		new->key = NULL;
	if (value)
		new->value = strdup(value);
	else
		new->value = NULL;
	return (new);
}
#include <stdio.h>
int	main(void)
{
	g_minishell.envp = NULL;

	t_list	*envpl;
	t_envp	*envp;
	t_exec	*data;
	envpl = create_l();
	envp = create_e("a", NULL);
	g_minishell.envp = envpl;
	envpl->data = (void *)envp;

	envpl = create_l();
	envp = create_e("b", "test");
	g_minishell.envp->next = envpl;
	envpl->data = envp;

	envpl = create_l();
	envp = create_e("d", "hi");
	g_minishell.envp->next->next = envpl;
	envpl->data = envp;

	data = (t_exec*)malloc(sizeof(t_exec));
	data->cmd = strdup("unset");
	data->cmd_path = strdup("/bin/unset");
	data->cmd_argv = (char **)malloc(sizeof(char *) * 7);
	data->cmd_argv[0] = strdup("unset");
	data->cmd_argv[1] =strdup("1");
	data->cmd_argv[2] =strdup("2");
	data->cmd_argv[3] =strdup("a");
	data->cmd_argv[4] =strdup("b");
	data->cmd_argv[5] =strdup("c");
	data->cmd_argv[6] = NULL;
	ft_unset(data, 0);
	while (g_minishell.envp)
	{
		envp = (t_envp * )g_minishell.envp->data;
		printf("[%s : %s]\n", envp->key, envp->value);
		g_minishell.envp = g_minishell.envp->next;
	}
	while (1)
		;	
}
#endif