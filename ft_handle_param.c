/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:32:30 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/27 22:35:26 by jraymond         ###   ########.fr       */
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
	int	len;

	len = ft_strlen(str);
	if (elem->flags & ZERO)
		ft_memset(&elem->buff[elem->i_buff], '0', nb_c_add);
	else
		ft_memset(&elem->buff[elem->i_buff], ' ', nb_c_add);
	elem->i_buff += nb_c_add;
	if (elem->flags & PRECI)
	{
		ft_strncat(&elem->buff[elem->i_buff], str, elem->precision);
		elem->i_buff += (elem->precision > len) ? len : elem->precision;
	}
	else
	{
		ft_strcpy(&elem->buff[elem->i_buff], str);
		elem->i_buff += len;
	}
}

void	ft_addstr_with_minus(t_printf *elem, char *str, int nb_c_add)
{
	int	len;

	len = ft_strlen(str);
	if (elem->flags & PRECI)
	{
		ft_strncat(&elem->buff[elem->i_buff], str, elem->precision);
		elem->i_buff += (elem->precision > len) ? len : elem->precision;
	}
	else
	{
		ft_strcpy(&elem->buff[elem->i_buff], str);
		elem->i_buff += len;
	}
	ft_memset(&elem->buff[elem->i_buff], ' ', nb_c_add);
	elem->i_buff += nb_c_add;
}

void	ft_param_string(t_printf *elem, va_list ap)
{
	int		nb_c_add;
	char	*str;

	(elem->flags & ZERO && elem->flags & MINUS) ? elem->flags ^= ZERO : 0;
	if (elem->type == 'S')
	{
		ft_handle_unicode(elem, ap);
		return ;
	}
	str = va_arg(ap, char*);
	nb_c_add = ft_howchar_add(elem, ft_strlen(str));
	if (elem->flags & ZERO || !(elem->flags & MINUS))
		ft_addstr_no_minus(elem, (char *)str, nb_c_add);
	else
		ft_addstr_with_minus(elem, str, nb_c_add);
}

void	ft_handle_param(t_printf *elem, va_list ap)
{
	if (elem->type == 's' || elem->type == 'S')
		ft_param_string(elem, ap);
}
