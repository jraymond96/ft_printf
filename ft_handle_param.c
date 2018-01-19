/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:32:30 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/19 22:09:25 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_param_string(t_printf *elem, va_list ap)
{
	int		length;
	int		res;
	char	*str;

	str = va_arg(ap, char*);	
	length = ft_strlen(str);
	(elem->flags & ZERO && elem->flags & MINUS) ? elem->flags ^= ZERO : 0;
	if ((res = length - elem->precision) > 0)
	{
		if (elem->flags & ZERO)
		{
			ft_memset(&elem->buff[elem->i_buff], '0', (elem->width - res));
			elem->i_buff += elem->width - res;
			ft_memcpy(&elem->buff[elem->i_buff], str, elem->precision);
		}
		else if (!(elem->flags & ZERO) && !(elem->flags & MINUS))
		{
			ft_memset(&elem->buff[elem->i_buff], ' ', (elem->width - res));
			elem->i_buff += elem->width - res;
			ft_memcpy(&elem->buff[elem->i_buff], str, elem->precision);
		}
		else if (elem->flags & MINUS)
		{
			ft_memcpy(&elem->buff[elem->i_buff], str, elem->precision);
			elem->i_buff += elem->precision;
			ft_memset(&elem->buff[elem->i_buff], ' ', (elem->width - res));
		}
	}
}

void	ft_handle_param(t_printf *elem, va_list ap)
{
	if (elem->type == 's')
		ft_param_string(elem, ap);
}
