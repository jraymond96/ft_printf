/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Check_Flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:01:58 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/18 12:34:16 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_printf elem)
{
	ft_bzero(elem->buff, 500);
	elem->length = 0;
	elem->i_buff;
	elem->flags = '\0';
	elem->width = 0;
	elem->precision = 0;
	elem->type = '\0';
}

int		ft_Analyse_Spe_Format(t_printf elem, const char format)
{
	int	i;

	i = 0;
	while (format[i++])
	{
		if (format[i] == '%')
			format = ft_Deal_Flags(elem, &format[i])
		elem->buff[elem->i_buff] = format[i];
	}

char	*ft_Deal_Flags(t_printf elem, char *format)
{
	int	i;

	i = 0;
	while (format[i] != '%')
	{
	return (0);
}
