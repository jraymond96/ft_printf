/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:59:58 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/15 14:15:33 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_struct(t_printf *elem)
{
	elem->length = 0;
	elem->i_buff = 0;
	elem->i_flags = 0;
	elem->width = 0;
	elem->precision = 0;
	elem->type = '\0';
	ft_bzero(elem->buff, 500);
	ft_bzero(elem->flags, 6);
}

t_printf		ft_readformat(const char *format, va_list ap)
{
	t_printf	elem;
	int			i;

	i = -1;
	ft_init_struct(&elem);
	while (format[++i])
	{
		if (format[i] == '%')
			i = i + ft_analyse_speconversion(&elem, &format[elem.i_buff], ap);
		elem.buff[elem.i_buff++] = format[i];
	}
	return (elem);
}

int			ft_analyse_speconversion(t_printf *elem, const char *format, va_list ap)
{
	int		index;

	index = 0;
	while (!(elem->type = ft_char_is_type(format[index])) && format[index])
	{
		/*think about work if we have 6 and more flags and 2 identical flags*/
		if (format[index] == '-' || format[index] == '+' || format[index] == '0'
				|| format[index] == '#' || format[index] == ' ')
		{
			elem->flags[elem->i_flags] = format[index];
			elem->i_flags++;
		}
		index++;
	}
	/*hear deal w p s*/
	ft_argis_str(ap, elem);
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
