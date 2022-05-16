/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 03:30:30 by hena              #+#    #+#             */
/*   Updated: 2022/05/17 03:30:31 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#define TRUE 1
#define FALSE 0

extern t_minishell	g_minishell;

static int	check_option(char *str)
{
	if (str[0] == '-')
		return (TRUE);
	else
		return (FALSE);
}

void	ft_pwd(t_exec *data, int pipe_flag)
{
	char	*now_path;
	char	**argv;

	argv = data->cmd_argv;
	argv++;
	if (*argv && check_option(*argv))
	{
		write(2, "option T.T\n", 11);
		exit(1);
	}
	now_path = NULL;
	now_path = getcwd(NULL, 256);
	if (now_path == NULL)
	{
		write(2, "fail getcwd()\n", 11);
		exit(1);
	}
	write(1, now_path, strlen(now_path));	//TODO:: strlen
	write(1, "\n", 1);
	// ft_putendl_fd(now_path, 1);			//TODO:: ft_putendl_fd 위를 지우든 이거를 지우든
	g_minishell.state = 0;
	free(now_path);
	if (pipe_flag)
		exit(0);
}

#if 0
// 확인 완료---------------- strlen이나 ft_putendl_fd만 처리
int	main(void)
{
	t_exec	*data;

	data = (t_exec *)malloc(sizeof(t_exec));
	data->cmd = strdup("pwd");
	data->cmd_path = strdup("/bin/pwd");
	data->cmd_argv = (char **)malloc(sizeof(char *) * 4);
	data->cmd_argv[0] = strdup("pwd");
	data->cmd_argv[1] = strdup("sdafasd");
	data->cmd_argv[2] = strdup("-p");
	data->cmd_argv[3] = NULL;
	ft_pwd(data, 0);
}
#endif
