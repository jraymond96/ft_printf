/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:59:58 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/08 15:08:13 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_analyse_speconversion(t_printf *elem, const char *format)
{
	int	index;

	index = 1;
	while (!(elem->type = ft_char_is_type(format[index])) && format[index])
	{
		if (format[index] == '-' || format[index] == '+' || format[index] == '0'
				|| format[index] == '#' || format[index] == ' ')
		{
			ft_deal_flags(elem, &format[index]);
			index++;
		}
		else if (format[index] == '.')
			index = index + ft_deal_precision(elem, &format[index]);
		else if (ft_isdigit(format[index]))
			index = index + ft_deal_width(elem, &format[index]);
		else if (ft_strchr("lhjz", format[index]))
			index = index + ft_deal_size(elem, &format[index]);
		else
			index++;
	}
	return (index);
}

int		ft_read_format(const char *format, va_list ap, t_printf *elem)
{
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i += ft_analyse_speconversion(elem, &format[i]);
			if (ft_handle_param(elem, ap) == -1)
			{
				write (1, elem->buff, elem->save);
				return (-1);
			}
			elem->save = elem->i_buff;
			elem->width = 0;
			elem->flags = '\0';
			elem->size = '\0';
		}
		else
			ft_handle_overflow(elem, (void *)&format[i], 1, 1);
	}
	return (0);
}

char	ft_char_is_type(char c)
{
	if (c == 's' || c == 'S')
		return (c);
	if (c == 'c' || c == 'C')
		return (c);
	if (c == 'd' || c == 'D' || c == 'i')
		return (c);
	if (c == 'u' || c == 'U')
		return (c);
	if (c == 'o' || c == 'O')
		return (c);
	if (c == 'x' || c == 'X')
		return (c);
	if (c == '%')
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
