/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:13:42 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/07 14:20:58 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countint(int nb, int base)
{
	int		len;

	if (nb == 0)
		return (1);
	len = 0;
	(nb < 0 && base == 10) ? len++ : 0;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len++);
}

char	*ft_itoa_base(int nb, int base)
{
	int		len;
	char	*buf;
	char	rest[17];
	int		sign;

	ft_strcpy(rest, "0123456789ABCDEF");
	len = ft_countint(nb, base);
	if (!(buf = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	buf[len] = '\0';
	len--;
	sign = (nb < 0 && base == 10) ? 1 : 0;
	while (len >= 0)
	{
		buf[len] = rest[ft_abs((nb % base))];
		len--;
		nb /= base;
	}
	sign == 1 ? buf[0] = '-': 0;
	return (buf);
}
