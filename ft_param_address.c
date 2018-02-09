/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:24:48 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/09 19:18:52 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padd_numbaddr(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{	
	char	zerox[3];
	char	sp;
	char	zero;
	
	ft_strcpy(zerox, "0x");
	sp = ' ';
	zero = '0';
	if (!(elem->flags & MINUS))
	{
		ft_handle_overflow(elem, &sp, nbca->width, 1);
		ft_handle_overflow(elem, zerox, 2, 2);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
	}
	else
	{
		ft_handle_overflow(elem, zerox, 2, 2);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
}

int	ft_hexa_len(unsigned long arg)
{
	int	len;
	
	len = 2;
	if (!arg)
		return (3);
	while(arg)
	{
		arg /= 16;
		len++;
	}
	return (len);
}

int	ft_param_address(t_printf *elem, va_list ap)
{
	unsigned long	arg;
	char		*numb;
	t_nbcaddpw	nbca;

	elem->flags &= 4;
	arg = va_arg(ap, unsigned long);
	numb = ft_ulltoa_base(arg, 16);
	nb_c_add_pw(&nbca, elem, ft_hexa_len(arg), numb);
	ft_padd_numbaddr(elem, &nbca, numb);
	ft_memdel((void *)&numb);
	return (0);
}
