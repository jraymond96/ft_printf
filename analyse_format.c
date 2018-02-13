/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:59:58 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/13 17:17:09 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_analyse_speconversion(t_printf *elem, const char *format)
{
	int	i;

	i = 1;
	while (!(elem->type = ft_char_is_type(format[i])) && format[i])
	{
		if (format[i] == '-' || format[i] == '+' || format[i] == '0'
				|| format[i] == '#' || format[i] == ' ')
			ft_deal_flags(elem, &format[i++]);
		else if (format[i] == '.')
			i = i + ft_deal_precision(elem, &format[i]);
		else if (ft_isdigit(format[i]))
			i = i + ft_deal_width(elem, &format[i]);
		else if (ft_strchr("lhjz", format[i]))
			i += ft_deal_size(elem, &format[i]);
		else
		{
			elem->no_type = !(elem->no_type) ? i : elem->no_type;
			i += ft_handle_notype(elem, format);
			break ;
		}
	}
	(elem->type == '%') ? ft_handle_notype(elem, format) : 0;
	return ((!(format[i]) || (elem->type == '%' && format[i] != '%') || (elem->no_type && format[i] == '%')) ? i - 1 : i);
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
			if (elem->type == '{')
			{
				ft_param_color(elem, &format[++i]);
				while (format[i] != '}')
					i++;
			}
			else if (ft_handle_param(elem, ap) == -1)
			{
				write (1, elem->buff, elem->save);
				return (-1);
			}
			elem->no_type = 0;
			elem->type = '0';
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
	else if (c == 'c' || c == 'C')
		return (c);
	else if (c == 'd' || c == 'D' || c == 'i')
		return (c);
	else if (c == 'u' || c == 'U')
		return (c);
	else if (c == 'o' || c == 'O')
		return (c);
	else if (c == 'x' || c == 'X')
		return (c);
	else if (c == 'p')
		return (c);
	else if (c == '%')
		return (c);
	else if (c == '{')
		return (c);
	return ('\0');
}
