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
#include "util.h"

#define TRUE 1
#define FALSE 0
#define MANYARGU 0
#define NUMBER 1

unsigned char	calculate_exit_number(int exit_num)
{
	return (exit_num);
}

void	print_exit_error(char *str, int type, int pipe_flag)
{
	_putstr_fd("bash: ", 2);
	_putstr_fd("exit: ", 2);
	if (type == MANYARGU)
	{
		_putendl_fd("too many arguments exit", 2);
		if (pipe_flag)
			exit(1);
	}
	else if (type == NUMBER)
	{
		_putstr_fd(str, 2);
		_putstr_fd(": ", 2);
		_putendl_fd("numeric argument required", 2);
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

long long	ft_atoi(char *str)
{
	int			flag;
	long long	sum;

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
	return (sum * flag);
}
