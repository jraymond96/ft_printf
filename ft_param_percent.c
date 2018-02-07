/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:14:02 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/07 11:14:04 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_param_percent(t_printf *elem)
{
	char	zero;
	char	space;
	char	percent;

	percent = '%';
	zero = '0';
	space = ' ';
	elem->width -= (elem->width - 1 >= 0) ? 1 : elem->width;
	elem->flags & MINUS && elem->flags & ZERO ? elem->flags ^= ZERO : 0;
	if (elem->flags & MINUS)
	{
		ft_handle_overflow(elem, &percent, 1, 1);
		ft_handle_overflow(elem, &space, elem->width, 1);	
	}
	else
	{
		if (elem->flags & ZERO)
			ft_handle_overflow(elem, &zero, elem->width, 1);
		else
			ft_handle_overflow(elem, &space, elem->width, 1);
		ft_handle_overflow(elem, &percent, 1, 1);
	}
	return (0);
}
