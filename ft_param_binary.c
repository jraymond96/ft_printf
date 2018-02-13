/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:53:25 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/13 23:34:08 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_param_binary(t_printf *elem, va_list ap)
{
	unsigned long long 	arg;
	long long			u_arg;

	if (elem->size & LL)
		u_arg = va_arg(ap, unsigned long long);
	else
		arg = va_arg(ap, long long);
	if (elem->size & H)
	{
		if (elem->size & LL)
			ft_print_ubinary(elem, u_arg, sizeof(char));
		else
			ft_print_binary(elem, arg, sizeof(char));
	}
	else if (elem->size & HH)
	{
		if (elem->size & LL)
			ft_print_ubinary(elem, u_arg, sizeof(short));
		else
			ft_print_binary(elem, arg, sizeof(short));
	}
	else if (elem->size & L)
	{
		if (elem->size & LL)
			ft_print_ubinary(elem, u_arg, sizeof(int));
		else
			ft_print_binary(elem, arg, sizeof(int));
	}
	else
	{
		if (elem->size & LL)
			ft_print_ubinary(elem, arg, sizeof(char));
		else
			ft_print_binary(elem, arg, sizeof(char));
	}
	return (0);
}
