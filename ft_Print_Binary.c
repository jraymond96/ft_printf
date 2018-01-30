/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 21:47:11 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/30 15:46:34 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CHAR (1 << i)

int		ft_print_binary(char binary)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (!((i + 1) % 4))
			ft_putchar('|');
		binary & CHAR ? ft_putnbr(1) : ft_putnbr(0);
		i--;
	}
	ft_putchar('\n');
	return (0);
}
