/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/08 12:46:59 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	/*printf("\nret %d\n", printf("|%010d|\n", 123));*/
	//printf("\nret %d\n", printf("%--.4u et |%#O||%#012O||%1lc|\n", -12, 0, 0, 95));
	//printf("\nret %d\n", ft_printf("%--.4u et |%#O||%#012O||%1lc|\n", -12, 0, 0, 95));
	printf("\nret %d\n", printf("|%0.8X|", 158));
	printf("\nret %d\n", ft_printf("|%#010.15O|", 0));
	return (0);
}
