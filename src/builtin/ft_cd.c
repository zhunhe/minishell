/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:30:56 by hena              #+#    #+#             */
/*   Updated: 2022/05/19 00:30:59 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#include "built_in.h"
#include "util.h"

#define TRUE 1
#define FALSE 0

extern t_minishell	g_minishell;

int	check_option(char *str, char *now)
{
	if (!_strncmp(str, "-P", 2) || !_strncmp(str, "-L", 2))
	{
		free(now);
		return (TRUE);
	}
	return (FALSE);
}


void	ft_cd(t_exec *data, int pipe_flag)
{
	char	**argv;
	char	*now;

	now = getcwd(NULL, 256);
	argv = data->cmd_argv;
	argv++;
	if (home_check(*argv, now))
		return ;
	if (check_option(*argv, now))
		return ;
	if (!_strcmp(*argv, "-"))
	{
		change_to_old_path(now);
		free(now);
		return ;
	}
	if (chdir(*argv) == -1 && *argv != NULL)
	{
		print_error_cd(*argv);
		exit(1);
	}
	free(now);
	if (pipe_flag)
		exit(0);
}

// #if 0
// t_list *create_l()
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	new->data = 0;
// 	new->next = 0;
// 	return (new);
// }

// t_envp *create_e(char *key, char *value)
// {
// 	t_envp	*new;

// 	new = (t_envp *)malloc(sizeof(t_envp));
// 	if (key)
// 		new->key = strdup(key);
// 	else
// 		new->key = NULL;
// 	if (value)
// 		new->value = strdup(value);
// 	else
// 		new->value = NULL;
// 	return (new);
// }
// #include <stdio.h>
// int	main(void)
// {
// 	g_minishell.envp = NULL;
// 	g_minishell.oldpwd = NULL;
// 	t_list	*envpl;
// 	t_envp	*envp;
// 	t_exec	*data;
// 	envpl = create_l();
// 	envp = create_e("HOME", "a");
// 	g_minishell.envp = envpl;
// 	envpl->data = (void *)envp;

// 	envpl = create_l();
// 	envp = create_e("b", "test");
// 	g_minishell.envp->next = envpl;
// 	envpl->data = envp;

// 	envpl = create_l();
// 	envp = create_e("d", "hi");
// 	g_minishell.envp->next->next = envpl;
// 	envpl->data = envp;

// 	data = (t_exec*)malloc(sizeof(t_exec));
// 	data->cmd = strdup("cd");
// 	data->cmd_path = strdup("/bin/cd");
// 	data->cmd_argv = (char **)malloc(sizeof(char *) * 7);
// 	data->cmd_argv[0] = strdup("cd");
// 	data->cmd_argv[1] = strdup("~");
// 	data->cmd_argv[2] = NULL;
// 	// data->cmd_argv[3] =strdup("f=1");
// 	data->cmd_argv[3] = NULL;
// 	// data->cmd_argv[1] =strdup("1=a");
// 	// printf("%s\n", getcwd(NULL, 256));
// 	ft_cd(data, 0); 
// 	printf("%s\n", getcwd(NULL, 256));
// 	// printf("%s\n", g_minishell.oldpwd);
	
// 	// data->cmd_argv[4] =strdup("b=2");
// 	// data->cmd_argv[5] =strdup("c=3");
// 	// data->cmd_argv[6] = NULL;
	
// 	// data->cmd_argv[1] = NULL;
// 	// ft_cd(data, 0);
// 	while (1)
// 		;
// }
// // #endif
