/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:03:04 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/30 14:59:04 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wctype.h>
#include <locale.h>

int		main()
{
	wchar_t	unicode;
	char	str[5];

	setlocale(LC_ALL, "");
	unicode = 178;;
	ft_bzero(str, 5);
	if ((unicode > 55295 && unicode < 57344) || unicode > 1114111 ||
			(unicode > 255 && MB_CUR_MAX <= 1))
		return (NULL);
	if (unicode >= 0 && unicode <= 127)
		str[0] = unicode;
	else if (unicode >= 128 && unicode <= 2047)
	{
		str[0] = (unicode >> 6) | 192;
		str[1] = (unicode & 63) | (1 << 7);
	}
	else if ((unicode >= 2048 && unicode <= 55295) || 
				(unicode >= 57344 && unicode <= 65535))
	{
		str[0] = (unicode >> 12) | 224;
		str[1] = ((unicode >> 6) & 63) | (1 << 7);
		str[2] = (unicode & 63) | (1 << 7);
	}
	else if ((unicode >= 65536 && unicode <= 1114111) && MB_CUR_MAX > 1)
	{
		str[0] = (unicode >> 18) | 240;
		str[1] = ((unicode >> 12) & 63) | (1 << 7);
		str[2] = ((unicode >> 6) & 63) | (1 << 7);
		str[3] = (unicode & 63) | (1 << 7);
	}
	else
		return (-1);
	write(1, str, MB_CUR_MAX);
	return (0);
}

