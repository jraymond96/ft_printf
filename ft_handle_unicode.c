/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:45:03 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/26 17:18:49 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unicodelen(wchar_t unicode)
{
	if (unicode <= 127 && unciode >= 0)
}

void	ft_handle_unciode(t_printf *elem, va_list ap)
{
	wchar_t *unicode;
	char	str[5];

	ft_bzero(str, 5);
	unicode = va_arg(ap, wchar_t*);
}
