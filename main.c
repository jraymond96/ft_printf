/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/08 21:05:04 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*str;

	str = malloc(58);
	/*printf("\nret %d\n", printf("|%010d|\n", 123));*/
	//printf("\nret %d\n", printf("%--.4u et |%#O||%#012O||%1lc|\n", -12, 0, 0, 95));
	//printf("\nret %d\n", ft_printf("%--.4u et |%#O||%#012O||%1lc|\n", -12, 0, 0, 95));
	printf("\nret %d\n", printf("|%#6o|", 0));
	printf("\nret %d\n", ft_printf("|%#6o|", 0));
	return (0);
}
