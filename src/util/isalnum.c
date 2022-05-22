/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:07:25 by juhur             #+#    #+#             */
/*   Updated: 2022/05/22 12:30:35 by juhur            ###   ########.fr       */
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

int	_isalpha(char c)
{
	return (_isupper(c) || _islower(c));
}

int	_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	_isalnum(char c)
{
	return (_isalpha(c) || _isdigit(c));
}
