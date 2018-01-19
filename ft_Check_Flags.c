/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Check_Flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:01:58 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/19 15:38:19 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deal_flags(t_printf *elem, const char *format)
{
	if (*format == '0' && (*(format - 1) == '%' || !ft_isdigit(*(format - 1))))
		elem->flags |= ZERO;
	if (*format == '-')
		elem->flags |= MINUS;
	if (*format == '+')
		elem->flags |= MORE;
	if (*format == '#')
		elem->flags |= SHARP;
	if (*format == ' ')
		elem->flags |= SPACE;
}

int		ft_deal_precision(t_printf *elem, const char *format)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (!ft_isdigit(format[i]) && format[i])
		i++;
	while (ft_isdigit(format[i]) && format[i])
	{
		res = res * 10 + (format[i] - '0');
		i++;
	}
	elem->precision = res;
	return (i);
}

int		ft_deal_width(t_printf *elem, const char *format)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (ft_isdigit(format[i]))
	{
		res = res * 10 + (format[i] - '0');
		i++;
	}
	elem->width = res;
	return (--i);
}

int		ft_deal_size(t_printf *elem, const char *format)
{
	int	i;

	i = 0;
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
		{
			elem->size |= HH;
			return (++i);
		}
		elem->size |= H;
	}
	if (*format == 'l')
	{
		if (*(format + 1) == 'l')
		{
			elem->size |= LL;
			return (++i);
		}
		elem->size |= L;
	}
	(*format == 'j') ? elem->size |= J : 0;
	(*format == 'z') ? elem->size |= Z : 0;
	return (i);
}
