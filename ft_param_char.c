/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:56:05 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/30 22:48:24 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_param_char(t_printf *elem, va_list ap)
{
	char	n[2];
	wchar_t	uni;
	int		res;
	char	unicode[5];

	ft_bzero(unicode, 5);
	ft_bzero(n, 2);
	(elem->flags & MINUS && elem->flags & ZERO) ? elem->flags ^= ZERO : 0;
	elem->flags & PRECI ? elem->flags ^= PRECI : 0;
	if (elem->type == 'C' || elem->size & L)
	{
		uni = va_arg(ap, wchar_t);
		res = ft_unicodelen(uni);
		res = ((elem->width - res) > 0) ? elem->width - res : 0;
		if ((elem->flags & ZERO || !(elem->flags & MINUS)) && res)
			ft_addstr_no_minus(elem, unicode, res);
		unicode_to_str(uni, unicode);
		ft_handle_overflow(elem, unicode, ft_strlen(unicode), 2);
		ft_bzero(unicode, 5);
		if (elem->flags & MINUS && res)
			ft_addstr_with_minus(elem, unicode, res);
		return ;
	}
	n[0] = (char)va_arg(ap, int);
	res = ft_howchar_add(elem, 1);
	if (res == 0)
		ft_handle_overflow(elem, n, 1, 2);
	else if (elem->flags & ZERO || !(elem->flags & MINUS))
		ft_addstr_no_minus(elem, n, res);
	else
		ft_addstr_with_minus(elem, n, res);
}
