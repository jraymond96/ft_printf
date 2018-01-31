/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:32:30 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/31 19:25:16 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_howchar_add(t_printf *elem, int len)
{
	int	length;

	length = elem->width;
	if (!(elem->flags & PRECI))
	{
		if ((len = length - len) < 0)
			return (0);
		else
			return (len);
	}
	if (elem->flags & PRECI && elem->precision < len)
		len = (elem->precision < length) ? length - elem->precision : 0;
	else
		len = (len > length) ? 0 : length - len;
	return (len);
}

void	ft_addstr_no_minus(t_printf *elem, char *str, int nb_c_add)
{
	int		len;
	char	c;
	char	sp;

	c = '0';
	sp = ' ';
	len = ft_strlen(str);
	if (elem->flags & ZERO)
		ft_handle_overflow(elem, &c, nb_c_add, 1);
	else
		ft_handle_overflow(elem, &sp, nb_c_add, 1);
	if (elem->flags & PRECI && len && elem->precision < len)
		ft_handle_overflow(elem, str, elem->precision, 2);
	else if ((!(elem->flags & PRECI) || elem->precision >= len) && len)
		ft_handle_overflow(elem, str, len, 2);
}

void	ft_addstr_with_minus(t_printf *elem, char *str, int nb_c_add)
{
	int		len;
	char	c;

	c = ' ';
	len = ft_strlen(str);
	if (elem->flags & PRECI && len && elem->precision < len)
		ft_handle_overflow(elem, str, elem->precision, 2);
	else if ((!(elem->flags & PRECI) || elem->precision >= len) && len)
		ft_handle_overflow(elem, str, len, 2);
	ft_handle_overflow(elem, &c, nb_c_add, 1);
}

int		ft_param_string(t_printf *elem, va_list ap)
{
	int		nb_c_add;
	char	*str;

	(elem->flags & ZERO && elem->flags & MINUS) ? elem->flags ^= ZERO : 0;
	if (elem->type == 'S' || elem->size & L)
	{
		if (ft_handle_unicode(elem, ap) == -1)
			return (-1);
		return (0);
	}
	if (!(str = va_arg(ap, char*)))
	{
		nb_c_add = ft_howchar_add(elem, 6);
		if (elem->flags & ZERO || !(elem->flags & MINUS))
			ft_addstr_no_minus(elem, "(null)", nb_c_add);
		else
			ft_addstr_with_minus(elem, "(null)", nb_c_add);
		return (0);
	}
	nb_c_add = ft_howchar_add(elem, ft_strlen(str));
	if (elem->flags & ZERO || !(elem->flags & MINUS))
		ft_addstr_no_minus(elem, (char *)str, nb_c_add);
	else
		ft_addstr_with_minus(elem, str, nb_c_add);	
	return (0);
}

int		ft_handle_param(t_printf *elem, va_list ap)
{
	int res;

	res = 0;
	if (elem->type == 's' || elem->type == 'S')
		res = ft_param_string(elem, ap);
	if (elem->type == 'c' || elem->type == 'C')
		res = ft_param_char(elem, ap);
	if (elem->type == 'd'|| elem->type == 'D')
		res = ft_param_decimal(elem, ap);
	return (res);
}
