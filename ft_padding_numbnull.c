/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_numbnull.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:12:57 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/08 12:41:56 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding_numbnull(t_printf *elem, t_nbcaddpw *nbca)
{	
	char	sp;
	char	more;

	sp = ' ';
	more = '+';
	if (elem->flags & MINUS)
	{
		ft_handle_overflow(elem, &sp, nbca->width, 1);
		if (elem->flags & MORE)
			ft_handle_overflow(elem, &more, 1, 1);
	}
	else
	{
		if (elem->flags & MORE)
			ft_handle_overflow(elem, &more, 1, 1);
		ft_handle_overflow(elem, &sp, nbca->width, 1);
	}
}

int		ft_padd_octnull(t_printf *elem, t_nbcaddpw * nbca)
{	
	char	sp;
	char	zero;

	sp = ' ';
	zero = '0';
	if (elem->flags & ZERO && nbca->width && !(nbca->preci))
		return (0);
	if (nbca->preci && !(nbca->width))
	{	
		ft_handle_overflow(elem, &zero, (nbca->preci + 1), 1);
		return (1);
	}
	if (nbca->width && nbca->preci)
	{
		nbca->width += 1;
		elem->flags ^= SHARP;
		return (0);
	}
	return (2);
}

int		ft_padding_octnull(t_printf *elem, t_nbcaddpw *nbca)
{
	char	sp;
	char	zero;
	int		res;

	sp = ' ';
	zero = '0';
	if (elem->flags & SHARP)
	{
		res = ft_padd_octnull(elem, nbca);
		if (res == 1 || res == 0)
			return (res);
		if (!(nbca->width && nbca->preci) && elem->width)
			ft_handle_overflow(elem, &sp, 1, 1);
		elem->flags ^= SHARP;
		if (!(elem->flags & PRECI) && nbca->width)
			ft_handle_overflow(elem, &sp, 1, 1);
		if (nbca->preci)
			nbca->preci -= 1;
		else
			nbca->width > 0 ? nbca->width -= 1 : 0;
	}
	return (0);
}
