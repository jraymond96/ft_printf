/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/13 20:39:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	c;

	c = 'a';
	ft_print_binary((void *)&c, sizeof(c));
	printf("ret : %d\n", printf("{%*d}", -5, 42));
	printf("ret : %d\n", ft_printf("{%*d}", -5, 42));
	return (0);
	write(1 ,"\e[36msalut", 10);
	return (0);
}
