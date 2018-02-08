/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:51:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/08 13:05:32 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_param_hexa(t_printf *elem, va_list ap)
{
	uintmax_t	arg;
	char		*numb;

	arg = ft_handle_uhexasize(elem, ap);
	numb = ft_ulltoa(arg, 16);
	if (elem->flags & ZERO && (elem->flags & MINUS || elem->flags & PRECI))
		elem->flags ZERO ^= ZERO;
}
