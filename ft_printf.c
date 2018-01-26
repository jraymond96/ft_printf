/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:47:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/26 20:30:14 by jraymond         ###   ########.fr       */
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
	ft_putendl("result printf :");
	ft_putchar('\n');
	setlocale(LC_ALL, "");
	printf("|%7S|\n", L"ਉਢ");
	ft_putendl("result ft_printf :");
	ft_putchar('\n');
	ft_printf("|%0-10s|\n", "salut");
	return (0);
}
