/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:47:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/28 20:44:27 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <locale.h>

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	elem;

	va_start(ap, format);
	elem = ft_Read_Format(format, ap);
	ft_putstr(elem.buff);
	va_end(ap);
	return (0);
}

int	main()
{
	wchar_t s[5];

	s[0] = 0xf8ff;
	s[1] = 0xfdf0;
	s[2] = 0x1d11e;
	s[3] = ' ';
	s[4] = '\0';
	ft_putendl("result printf :");
	ft_putchar('\n');
	setlocale(LC_ALL, "");
	ft_putnbr(printf("amdjkndkqw|%-30S|\n", s));
	ft_putchar('\n');
	/*printf("|%.10d|\n", 123);
	printf("|%20.5d|\n", 123);*/
	ft_putendl("result ft_printf :");
	ft_putchar('\n');
	ft_printf("amdjkndkqw|%-30S|\n", s);
	return (0);
}
