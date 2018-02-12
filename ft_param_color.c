/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:09:39 by jraymond          #+#    #+#             */
/*   Updated: 2018/02/13 00:35:14 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_howc(const char *format)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (format[i] && (format[i] != '}' || format[i] != ','))
	{
		i++;
		nb++;
	}
	return (++nb);
}

char	ft_what_color(const char *format)
{
	int	nb;

	nb = ft_howc(format);
	ft_putstr(format);
	ft_putnbr(nb);
	if (!(ft_strncmp(format, "black", nb)))
		return ('0');
	else if (!(ft_strncmp(format, "red", nb)))
		return ('1');
	else if (!(ft_strncmp(format, "green", nb)))
		return ('2');
	else if (!(ft_strncmp(format, "pink", nb)))
		return ('3');
	else if (!(ft_strncmp(format, "blue", nb)))
		return ('4');
	else if (!(ft_strncmp(format, "yellow", nb)))
		return ('5');
	else if (!(ft_strncmp(format, "cyan", nb)))
		return ('6');
	else
		return ('7');
}

void	ft_buffer_color(char *code_color, t_printf *elem)
{
	int	res;

	res = BUFF_SIZE - elem->i_buff;
	if (res < (int)ft_strlen(code_color))
	{
		write(1, elem->buff, elem->i_buff);
		ft_bzero(elem->buff, BUFF_SIZE);
		elem->ret += elem->i_buff;
		elem->i_buff = 0;
	}
	ft_strcpy(&elem->buff[elem->i_buff], code_color);
	elem->i_buff += ft_strlen(code_color);
	
}

void	ft_param_color(t_printf *elem, const char *format)
{
	char	*back_color;
	char	*code_color;
	char	*tmp;

	ft_putstr("test\n");
	(!(code_color = ft_memalloc(14))) ? exit (1) : 0;
	tmp = code_color;
	ft_strcpy(code_color, "i[");
	code_color += 2;
	if (elem->flags & MORE)
	{
		*code_color = '7';
		code_color++;
		*code_color = ';';
		code_color++;
	}
	if (elem->flags & ZERO)
	{
		*code_color = '4';
		code_color++;
		*code_color = ';';
		code_color++;
	}
	if (elem->flags & SHARP)
	{
		*code_color = '1';
		code_color++;
		*code_color = ';';
		code_color++;
	}
	*code_color = '3';
	code_color++;
	*code_color = ft_what_color(format);
	code_color++;
	if ((back_color = ft_strcchr(format, ',', '}')))
	{
		*code_color = ';';
		code_color++;
		*code_color = '4';
		code_color++;
		*code_color = ft_what_color(++back_color);
		code_color++;
	}
	*code_color = 'm';
	ft_buffer_color(tmp, elem);
	ft_memdel((void **)&tmp);
}
