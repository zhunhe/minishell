/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:58:28 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 13:14:02 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minishell.h>

t_minishell	g_minishell;

int	error_arg(char *s)
{
	printf("minishell: %s No such file or directory\n", s);
	return (127);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
		return (error_arg(argv[1]));
	set_envp(envp);
	while (1)
		if (!print_prompt())
			break ;
	printf("\e[1A\e[10C exit\n");
	return (0);
}
