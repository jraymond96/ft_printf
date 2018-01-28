/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdebile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:35:47 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/28 17:05:02 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(void *data, int flags)
{
	if (flags == 1)
		ft_putchar(*(char *)data);
	else
		ft_putstr((char *)data);
	return (0);
}

int	main()
{
	char	c;
	char	str[3];

	c = 'A';
	str[0] = 'A';
	str[1] = 'B';
	str[2] = '\0';
	ft_print(&c, 1);
	ft_putchar('\n');
	return(0);
}
