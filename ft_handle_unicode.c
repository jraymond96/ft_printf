/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:45:03 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/26 20:49:30 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unicodelen(wchar_t unicode)
{
	if (unicode >= 0 && unciode <= 127)
		return(1);
	else if (unicode >= 128 && unciode <= 2047)
		return (2);
	else if (unicode >= 2048 && unciode <= 65535)
		return (3);
	else
		return (4);
}

int		ft_howunicode_print(t_printf *elem, wchar_t *unicode)
{
	
}

void	ft_handle_unciode(t_printf *elem, va_list ap)
{
	wchar_t *unicode;
	char	str[5];
	int		nb;
	int		i;

	i = 0;
	unicode = va_arg(ap, wchar_t*);
	nb = ft_unicodelen(unicode);
	ft_bzero(str, 5);
	while (unicode[i++])
	{
		if (elem->flags & PRECI &&
				(nb + ft_unicodelen(unicode[i])) > elem->precision)
			break;
		nb += ft_unicodelen(unicode[i]);
	}
	if (i > elem->precision)
		i--;
	ft_howchar_add(elem, nb)
}
