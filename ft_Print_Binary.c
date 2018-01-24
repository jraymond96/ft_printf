/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Print_Binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:52:35 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/24 10:01:23 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int n);
void	ft_putchar(char c);

#define CHAR (1 << i)

int		ft_Print_Binary(char binary)
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
