/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:00:56 by hena              #+#    #+#             */
/*   Updated: 2022/04/27 17:43:48 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#ifndef BOOL
#define BOOL

#define TRUE 1
#define FALSE 0

#endif

#ifndef EXITKIND
#define EXITKIND

#define MANYARGU 0
#define MANYARGUSIZE 25
#define NUMBER 1
#define NUMBERSIZE 27

#endif

extern t_minishell	g_minishell;

unsigned char	calculate_exit_number(int exit_num)
{
	return exit_num;
}

void	print_exit_error(char *str, int type, int pipe_flag)
{
	write(2, "bash: ", 6);
	write(2, "exit: ", 6);
	if (type == MANYARGU)
	{
		write(2, "too many arguments exit\n", MANYARGUSIZE);
		g_minishell.state = 1;
		if (pipe_flag)
			exit(1);
	}
	else if (type == NUMBER)
	{
		write(2, str, strlen(str));
		write(2, ": ", 2);
		write(2, "numeric argument required\n", NUMBERSIZE);
		g_minishell.state = 255;
		exit(255);		
	}
	
}

int	check_all_integer(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (FALSE);
		++str;
	}
	return (TRUE);
}

int	ft_atoi(char *str)
{
	int	flag;
	int	sum;

	sum = 0;
	flag = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str)
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sum);
}
