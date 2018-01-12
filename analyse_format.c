/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:59:58 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/12 20:47:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		ft_readformat(const char *format, va_list ap)
{
	t_printf	elem;
	int			i;

	i = -1;
	elem.i_buff = 0;
	elem.length = 0;
	elem.width = 0;
	elem.type = '\0';
	ft_bzero(elem.buff, 500);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i = i + ft_analyse_speconversion(&elem, &format[elem.i_buff]);
			ft_argis_str(ap, &elem);
		}
		elem.buff[elem.i_buff++] = format[i];
	}
	return (elem);
}

int			ft_analyse_speconversion(t_printf *elem, const char *format)
{
	int		index;

	index = 0;
	while (!(elem->type = ft_char_is_type(format[index])) && format[index])
	{
		if (format[index] == '-')
			elem->flags = format[index];
		index++;
	}
	return (++index);
}

char		ft_char_is_type(char c)
{
	if (c == 's' || c == 'S')
		return (c);
	return ('\0');
}

void	ft_argis_str(va_list ap, t_printf *elem)
{
	char	*arg;

	arg = va_arg(ap, char*);
	ft_strcpy(&elem->buff[elem->i_buff], arg);
	elem->i_buff = elem->i_buff + ft_strlen(arg);
}
