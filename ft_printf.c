/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:47:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/30 15:29:25 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	elem;

	ft_bzero(&elem, sizeof(t_printf));
	va_start(ap, format);
	if (ft_read_format(format, ap, &elem) == -1)
		return (-1);
	ft_putstr(elem.buff);
	va_end(ap);
	if (elem.ret == 0)
		return (elem.i_buff);
	else
		return (elem.ret);
}
