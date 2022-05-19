/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:07:25 by juhur             #+#    #+#             */
/*   Updated: 2022/05/20 03:12:08 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_isupper(char c)
{
	return ('A' <= c && c <= 'Z');
}

int	_islower(char c)
{
	return ('a' <= c && c <= 'z');
}

int	_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	_isalnum(char c)
{
	return (_isupper(c) || _islower(c) || _isdigit(c));
}