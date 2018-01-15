/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:47:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/15 16:42:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	elem;

	va_start(ap, format);
	elem = ft_readformat(format, ap);
	ft_putstr(elem.buff);
	va_end(ap);
	return (0);
}

int	main()
{
	ft_putendl("result printf :");
	ft_putchar('\n');
	printf("|%-010s|\n", "COUCOU");
/*	ft_putendl("result ft_printf :");
	ft_putchar('\n');
	ft_printf("salut %0-s coucou\n", "salut");*/
	return (0);
}
