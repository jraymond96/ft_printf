/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:47:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/18 12:34:18 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	elem;

	va_start(ap, format);
	ft_init_struct(&elem);
	ft_Deal_Flags(elem, format)
	ft_putstr(elem.buff);
	va_end(ap);
	return (0);
}

int	main()
{
	char		*tmp;

	ft_init_struct(&elem);
	ft_strcpy(format, "|%010 20s|\n");
	((tmp = ft_strchr(format, ' ')) && *(++tmp) == '0') ? flags |= ZERO : 0;
	ft_Print_Binary(flags);
	printf("format : %s\n", format);
	ft_putendl("result printf :");
	ft_putchar('\n');
	printf(format, "COUCOU");
/*	ft_putendl("result ft_printf :");
	ft_putchar('\n');
	ft_printf("salut %0-s coucou\n", "salut");*/
	return (0);
}
