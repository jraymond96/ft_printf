/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/01 23:02:01 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	/*printf("\nret %d\n", printf("|%010d|\n", 123));*/
	printf("\nret %d\n", printf("|%0 20+d|\n", 123));
	printf("\nret %d\n", ft_printf("|%0 20+d|\n", 123));
	return (0);
}
