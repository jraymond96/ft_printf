/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:59:02 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/01 22:51:42 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(intmax_t arg)
{
	int			i;
	intmax_t	res;

	i = 0;
	res = arg;
	if (res == 0)
		return (0);
	while (res)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

void	nb_c_add_pw(t_nbcaddpw *nbca, t_printf *elem, int intl, char *numb)
{
	int			i;

	ft_bzero(nbca, sizeof(t_nbcaddpw));
	if (elem->flags & PRECI)
		nbca->preci = (intl >= elem->precision) ? 0 : elem->precision - intl;
	i = nbca->preci;
	if (elem->width)
	{
		if (elem->flags & MORE || elem->flags & SPACE || numb[0] == '-')
			i++;
		nbca->width = (elem->width <= (i + intl)) ? 0 : elem->width - (i + intl);
	}
}

void	ft_handle_sign(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	sp;
	char	minus;
	char	more;

	sp = ' ';
	minus = '-';
	more = '+';
	if (numb[0] == '-')
		nbca->preci = (nbca->preci - 1) < 0 ? 0 : nbca->preci--;
	if (elem->flags & SPACE)
	{
		ft_handle_overflow(elem, &sp, 1, 1);
		nbca->width = (nbca->width - 1) < 0 ? 0 : nbca->width--;
	}
	if (elem->flags & MORE && elem->flags & ZERO)
	{
		ft_handle_overflow(elem, &more, 1, 1);
		nbca->width = (nbca->width - 1) < 0 ? 0 : nbca->width--;
		elem->flags ^= MORE;
	}
/*	{
		ft_handle_overflow(elem, &minus, 1, 1);
		nbca->preci = (nbca - 1) < 0 ? 0 : nbca->preci--;
	}
	else if (numb[0] == '-')
		nbca->preci = (nbca - 1) < 0 ? 0 : nbca->preci--;
	else if (elem->flags & MORE && (elem->flags & MINUS || !(nbca->width)))
	{
		ft_handle_overflow(elem, &more, 1, 1);
		nbca->preci = (nbca - 1) < 0 ? 0 : nbca->preci--;
	}
	else if (elem->flags & SPACE && (elem->flags & MINUS || !(nbca->width)))
	{
		ft_handle_overflow(elem, &space, 1, 1);
		nbca->preci = (nbca - 1) < 0 ? 0 : nbca->preci--;
	}*/
}

void	ft_padding_numbposi(t_printf *elem, t_nbcaddpw *nbca, char *numb)
{
	char	sp;
	char	zero;
	char	more;

	sp = ' ';
	more = '+';
	zero = '0';
	if (elem->flags & ZERO || !(elem->flags & MINUS))
	{
		if (!(elem->flags & ZERO))
			ft_handle_overflow(elem, &sp, nbca->width, 1);
		else
			ft_handle_overflow(elem, &zero, nbca->width, 1);
		if (elem->flags & MORE)
			ft_handle_overflow(elem, &more, 1, 1);
		ft_handle_overflow(elem, &zero, nbca->preci, 1);
		ft_handle_overflow(elem, numb, ft_strlen(numb), 2);
	}

}

int		ft_param_decimal(t_printf *elem, va_list ap)
{
	intmax_t	arg;
	char		*numb;
	t_nbcaddpw	nbca;
	
	arg = va_arg(ap, int);
	numb = ft_itoa(arg);
	if (elem->flags & ZERO && (elem->flags & MINUS || elem->flags & PRECI))
		elem->flags ^= ZERO;
	(elem->flags & SPACE && elem->flags & MORE) ? elem->flags ^= SPACE : 0;
	nb_c_add_pw(&nbca, elem, ft_intlen(arg), numb);
	ft_handle_sign(elem, &nbca, numb);
	ft_padding_numbposi(elem, &nbca, numb);
	free(numb);
	return (0);
}
