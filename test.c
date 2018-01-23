/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:03:04 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/23 21:37:47 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <wctype.h>

int		main()
{
	int		unicode;
	wchar_t str[5];

	unicode = 140;
	ft_bzero(str, 5);
	if (unicode >= 0 && unicode <= 127)
		str[0] = unicode;
	else if (unicode >= 128 && unicode <= 2047)
		str[0] &= TWOOCTET;
	else if (unicode >= 2048 && unicode <= 55295)
		;
	else if (unicode >= 57344 && unicode <= 65535)
		;
	else if (unicode >= 65536 && unicode <= 1114111)
		;
	else
		return (-1);
	ft_Print_Binary(str[0]);
	/*ft_putstr((const char*)str);*/
	return (0);
}

