/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:14:30 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/28 22:03:38 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_overflow(t_printf *elem, void *data, int nb, int spe)
{
	int	i;
	char	*data_b;

	data_b = (char *)data;
	while (nb)
	{
		i = 0;
		if ((elem->i_buff + nb) > BUFF_SIZE &&
				(i = BUFF_SIZE - elem->i_buff) == 0)
		{
			write(1, elem->buff, BUFF_SIZE);
			ft_bzero(elem->buff, BUFF_SIZE);
			elem->i_buff = 0;
		}
		else if ((elem->i_buff + nb) > BUFF_SIZE)
		{
			if (spe == 1)
				ft_memset(&elem->buff[elem->i_buff], *(char *)data, i);
			else if (spe == 2)
			{
				ft_strncat(&elem->buff[elem->i_buff] , data_b, i);
				data_b += i;
			}
			nb -= i;
			elem->i_buff += i;
		}
		else
		{
			if (spe == 1)
				ft_memset(&elem->buff[elem->i_buff], *(char *)data, nb);
			else if (spe == 2)
				ft_strncat(&elem->buff[elem->i_buff] , data_b, nb);
			elem->i_buff += nb;
			nb = 0;
		}
	}
}
