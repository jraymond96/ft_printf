/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/30 22:51:34 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	wchar_t s[4];

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	setlocale(LC_ALL, "");
	printf("\nret %d\n", printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
	printf("\nret %d\n", ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
	return (0);
}
