/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:05:41 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/02 17:51:31 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_countint(unsigned long long n)
{
	long	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len++);
}

char			*ft_ulltoa(unsigned long long n)
{
	unsigned long long	n_lenght;
	long				len;
	char				*buf;

	n_lenght = n;
	len = ft_countint(n_lenght);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	len--;
	while (len >= 0)
	{
		buf[len] = (n_lenght % 10) + '0';
		len--;
		n_lenght /= 10;
	}
	return (buf);
}
