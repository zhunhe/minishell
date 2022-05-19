/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:07:55 by juhur             #+#    #+#             */
/*   Updated: 2022/05/20 00:19:42 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <util.h>

static size_t	get_len(int n)
{
	size_t		len;
	long long	ll_n;

	ll_n = n;
	if (ll_n < 0)
		ll_n *= -1;
	if (ll_n == 0)
		len = 1;
	else
	{
		len = 0;
		while (ll_n)
		{
			++len;
			ll_n /= 10;
		}
	}
	if (ll_n < 0)
		return (len + 1);
	return (len);
}

char	*_itoa(int n)
{
	char		*ret;
	long long	ll_n;
	size_t		len;

	len = get_len(n);
	ret = _calloc(len + 1, sizeof(char));
	ll_n = n;
	if (ll_n < 0)
		ll_n *= -1;
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len] = (ll_n % 10) + '0';
		ll_n /= 10;
		if (len == 0)
		{
			if (n < 0)
				ret[len] = '-';
			break ;
		}
		--len;
	}
	return (ret);
}
