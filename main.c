/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:10 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/02 12:24:01 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	/*printf("\nret %d\n", printf("|%010d|\n", 123));*/
	printf("\nret %d\n", printf("|%-5.3d|\n", -42));
	printf("\nret %d\n", ft_printf("|%-5.3d|\n", -42));
	return (0);
}
