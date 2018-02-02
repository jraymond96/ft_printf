/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_numbnull.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:12:57 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/02 16:45:23 by jraymond         ###   ########.fr       */
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
