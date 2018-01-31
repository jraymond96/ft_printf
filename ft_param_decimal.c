/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:59:02 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/31 19:25:14 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(intmax_t arg)
{
	int			i;
	intmax_t	res;

	i = 0;
	res = arg;
	while (res)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

int		ft_param_decimal(t_printf *elem, va_list ap)
{
	intmax_t	arg;
	t_printf	*toto;
	int			i;
	
	toto = elem;
	arg = va_arg(ap, int);
	i = ft_intlen(arg);
	/*arg = ft_handle_size(elem, va_list ap)*/
	return (0);
}
