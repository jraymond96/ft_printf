/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:32:30 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/23 00:11:51 by jraymond         ###   ########.fr       */
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
	{
		if ((res = length - res) < 0)
			return (0);
		else
			return (res);
	}
	if (elem->flags & PRECI && elem->precision < res)
		res = (elem->precision < length) ? length - elem->precision : 0;
	else
		res = (res > length) ? 0 : length - res;
	return (res);
}

void	ft_param_string(t_printf *elem, va_list ap)
{
	int		length;
	char	*str;
	int		len;

	str = va_arg(ap, char*);
	length = ft_howchar_add(elem, str);
	len = ft_strlen(str);
	(elem->flags & ZERO && elem->flags & MINUS) ? elem->flags ^= ZERO : 0;
	if (elem->flags & PRECI)
	{
		if (elem->flags & MINUS)
		{
			ft_putstr("TqTq\n");
			ft_strncpy(&elem->buff[elem->i_buff], str, elem->precision);
			elem->i_buff += (elem->precision > len) ? len : elem->precision;
			ft_memset(&elem->buff[elem->i_buff], ' ', length);
		}
		else if (elem->flags & ZERO)
		{
			ft_putstr("TATA\n");
			ft_memset(&elem->buff[elem->i_buff], '0', length);
			elem->i_buff += length;
			ft_strncpy(&elem->buff[elem->i_buff], str, elem->precision);
		}
		else
		{
			ft_putstr("TuTu\n");
			ft_strncpy(&elem->buff[elem->i_buff], str, elem->precision);
			elem->i_buff += (elem->precision > len) ? len : elem->precision;
			ft_memset(&elem->buff[elem->i_buff], ' ', length);
		}
		elem->i_buff += elem->precision;
	}
	else
	{
		if (elem->flags & MINUS)
		{
			ft_putstr("TeTe\n");
			ft_strcpy(&elem->buff[elem->i_buff], str);
			printf("i_buff %d\n", elem->i_buff);
			elem->i_buff += len;
			printf("length %d\n", length);
			ft_memset(&elem->buff[elem->i_buff], ' ', length);
		}
		else if (elem->flags & ZERO)
		{
			ft_putstr("TdTd\n");
			ft_memset(&elem->buff[elem->i_buff], '0', length);
			elem->i_buff += length;
			ft_strcpy(&elem->buff[elem->i_buff], str);
		}
	  	else
		{
			ft_putstr("TvTv\n");
			ft_strcpy(&elem->buff[elem->i_buff], str);
			elem->i_buff += len;
			ft_memset(&elem->buff[elem->i_buff], ' ', length);
		}
		elem->i_buff += (length + len);
	}
}

void	ft_handle_param(t_printf *elem, va_list ap)
{
	if (elem->type == 's')
		ft_param_string(elem, ap);
}
