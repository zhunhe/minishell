/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:58:28 by juhur             #+#    #+#             */
/*   Updated: 2022/04/27 20:49:56 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	// TODO: envp -> linked list
	(void)envp;
	echoctl_off();
	print_prompt();
	return (0);
}
