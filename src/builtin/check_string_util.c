/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:06:19 by hena              #+#    #+#             */
/*   Updated: 2022/05/11 21:06:21 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOL
#define BOOL
#define TRUE 1
#define FALSE 0
#endif

int	is_small_alpha(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (TRUE);
	return (FALSE);
}

int	is_big_alpha(char ch)
{	
	if (ch >= 'A' && ch <= 'Z')
		return (TRUE);
	return (FALSE);
}

int	is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (TRUE);
	return (FALSE);
}
