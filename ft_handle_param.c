/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:32:30 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/20 23:08:13 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strjoinn_addn_char(char *dest, char *src, char c, int nchar, int n)
{
	int	i;

	i = nchar;
	i += n;
	ft_memset(dest, c, nchar);
	ft_strncpy(&dest[nchar], src, n);
	return (++i);
}

int		ft_howchar_add(t_printf *elem, char *str)
{
	int	res;
	int	length;

	length = elem->width;
	res = ft_strlen(str);
	if (!(elem->flags & PRECI))
		return (0);
	if (elem->flags & PRECI && elem->precision < res)
		res = (elem->precision < length) ? length - elem->precision : 0;
	else
		res = (res > length) ? 0 : length - res;
	return (res);
}
/*
void	ft_param_string(t_printf *elem, va_list ap)
{
	int		length;
	int		res;
	char	*str;

	str = va_arg(ap, char*);	
	length = ft_strlen(str);
	(elem->flags & ZERO && elem->flags & MINUS) ? elem->flags ^= ZERO : 0;
	if (elem->flags & PRECI)
	{
		elem->i_buff = ft_strjoinn_addn_char(&buff[elem->buff], str, '0', )
		res = length - elem->precision;
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
*/
void	ft_handle_param(t_printf *elem, va_list ap)
{
	char *str;

	int	i;
	str = va_arg(ap, char*);	
	if (elem->type == 's')
		i = ft_howchar_add(elem, str);
	ft_putnbr(i);
		/*ft_param_string(elem, ap);*/
}
