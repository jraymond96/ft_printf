/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:42:26 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/07 14:28:14 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countint(int n)
{
	long	len;

	if (n == 0)
		return (1);
	len = 0;
	(n < 0) ? len++ : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len++);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*buf;
	int		sign;

	len = ft_countint(n);
	if (!(buf = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	buf[len] = '\0';
	len--;
	sign = (n < 0) ? 1 : 0; 
	while (len >= 0)
	{
		buf[len] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	sign == 1 ? buf[0] = '-' : 0;
	return (buf);
}
