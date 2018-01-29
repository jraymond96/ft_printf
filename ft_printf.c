/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:47:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/29 18:57:05 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <locale.h>

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	elem;

	ft_bzero(&elem, sizeof(t_printf));
	va_start(ap, format);
	if (ft_Read_Format(format, ap, &elem) == -1)
		return (-1);
	ft_putstr(elem.buff);
	va_end(ap);
	if (elem.ret == 0)
		return (elem.i_buff);
	else
		return (elem.ret);
}

int	main()
{
	wchar_t s[5];

	s[0] = 0xf8ff;
	s[1] = 0xfdf0;
	s[2] = 0xd800;
	s[3] = ' ';
	s[4] = '\0';
	ft_putendl("result printf :");
	ft_putchar('\n');
	setlocale(LC_ALL, "");
	ft_putnbr(printf("amdjkndkqw|%030S|\n", s));
	ft_putchar('\n');
	ft_putendl("result ft_printf :");
	ft_putchar('\n');
	ft_putnbr(ft_printf("amdjkndkqw|%030S|\n", s));
	return (0);
}
