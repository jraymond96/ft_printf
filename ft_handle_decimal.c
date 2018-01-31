/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:14:52 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/31 19:01:00 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(intmax_t arg)
{
	int			i;
	intmax_t	res;

	i = 0;
	res = arg;
	while (arg)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

int		ft_param_decimal(t_printf *elem, va_list ap)
{
	intmax_t	arg;

	
	arg = va_arg(ap, int);
	/*arg = ft_handle_size(elem, va_list ap)*/
	ft_putnbr(ft_intlen(arg));
	return (0);
}
