/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:45:03 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/27 19:00:15 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unicodelen(wchar_t unicode)
{
	if ((MB_CUR_MAX <= 1 && unicode > 255) || (unicode > 55295 &&
				unicode < 57344) || unicode > 1114111)
		return (-1);
	if (unicode >= 0 && unicode <= 127)
		return(1);
	else if (unicode >= 128 && unicode <= 2047)
		return (2);
	else if (unicode >= 2048 && unicode <= 65535)
		return (3);
	else
		return (4);
}

int		ft_howunicode_print(t_printf *elem, wchar_t *unicode, int *nb)
{
	int	i;

	i = 0;
	*nb = ft_unicodelen(unicode[i]);
	if (!(elem->flags & PRECI))
	{
		while (unicode[++i])
			;
		return (i);
	}
	while (unicode[i++])
	{
		if (*nb >= elem->precision)
			break;
		printf("nb : %d\n", )
		*nb += ft_unicodelen(unicode[i]);
	}
	if (*nb > elem->precision)
	{
		*nb -= ft_unicodelen(unicode[--i]);
		return (i);
	}
	return (i);
}



void	ft_handle_unicode(t_printf *elem, va_list ap)
{
	wchar_t *unicode;
	char	str[5];
	int		nb;
	int		nbuni_print;
	int		i;

	nb = 0;
	i = 0;
	unicode = va_arg(ap, wchar_t*);
	ft_bzero(str, 5);
	nbuni_print = ft_howunicode_print(elem, unicode, &nb);
	printf("nb = %d\n", nb);
	nb = ft_howchar_add(elem, nb);
	printf("nb = %d\n", nb);
	if ((elem->flags & ZERO ||!(elem->flags & MINUS)) && nb)
		ft_addstr_no_minus(elem, str, nb);
	while (i < nbuni_print)
	{
		unicode_to_str(unicode[i], str);
		ft_strcpy(&elem->buff[elem->i_buff], str);
		elem->i_buff += ft_strlen(str);
		ft_bzero(str, 5);
		i++;
	}
	if (elem->flags & MINUS)
		ft_addstr_with_minus(elem, str, nb);
}
