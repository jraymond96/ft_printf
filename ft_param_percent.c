/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:14:02 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/10 00:25:03 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countnbcadd(const char *format)
{
	int	i;
	int	nb;

	i = 0;
	nb = -1;
	while (format[i] && format[i] != '%')
	{
		nb++;
		i++;
	}
	return (nb);
}

void	ft_handle_notype(t_printf *elem, const char *format)
{
	int		nb;
	char	sp;
	char	zero;

	sp = ' ';
	zero = '0';
	printf("no_type : %d\n", elem->no_type);
	if (format[elem->no_type] == '%')
	{
		ft_param_percent(elem);
		return ;
	}
	nb = ft_countnbcadd(&format[elem->no_type]);
	elem->width -= elem->width ? 1 : 0;
	if (elem->flags & MINUS)
	{
		ft_handle_overflow(elem, (void *)&format[elem->no_type], 1, 1);
		ft_handle_overflow(elem, &sp, elem->width, 1);
		ft_handle_overflow(elem, (void *)&format[elem->no_type], nb, 2);
	}
	else if (elem->flags & ZERO || !(elem->flags & MINUS))
	{
		if (elem->flags & ZERO)
			ft_handle_overflow(elem, &zero, elem->width, 1);
		else
			ft_handle_overflow(elem, &sp, elem->width, 1);
		ft_handle_overflow(elem, (void *)&format[elem->no_type], (nb + 1), 2);
	}
}

int		ft_param_percent(t_printf *elem)
{
	char	zero;
	char	space;
	char	percent;

	percent = '%';
	zero = '0';
	space = ' ';
	elem->width -= (elem->width - 1 >= 0) ? 1 : elem->width;
	elem->flags & MINUS && elem->flags & ZERO ? elem->flags ^= ZERO : 0;
	if (elem->flags & MINUS)
	{
		ft_handle_overflow(elem, &percent, 1, 1);
		ft_handle_overflow(elem, &space, elem->width, 1);	
	}
	else
	{
		if (elem->flags & ZERO)
			ft_handle_overflow(elem, &zero, elem->width, 1);
		else
			ft_handle_overflow(elem, &space, elem->width, 1);
		ft_handle_overflow(elem, &percent, 1, 1);
	}
	return (0);
}
