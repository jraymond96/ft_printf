#include "ft_printf.h"

int	ft_howc(const char *format)
{
	int	nb;

	nb = 0;
	while (*format || *format != '}' || *format != ',')
	{
		format++;
		nb++;
	}
	return (nb)
}

char	ft_what_color(const char *format)
{
	int	nb;

	nb = ft_howc(format);
	if (!(ft_strncmp(format, "black", nb)))
		return (0);
	else if (!(ft_strncmp(format, "red", nb)))
		return (1);
	else if (!(ft_strncmp(format, "green", nb)))
		return (2);
	else if (!(ft_strncmp(format, "pink", nb)))
		return (3);
	else if (!(ft_strncmp(format, "blue", nb)))
		return (4);
	else if (!(ft_strncmp(format, "yellow", nb)))
		return (5);
	else if (!(ft_strncmp(format, "cyan", nb)))
		return (6);
	else if (!(ft_strncmp(format, "gray", nb)))
		return (7);
	else
		return (0);
}

void	ft_buffer_color(char *code_color, t_printf *elem)
{
	int	res;

	res = BUFF_SIZE - elem->i_buff;
	if (res < ft_strlen(code_color))
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

	(!(code_color = ft_memalloc(12))) ? exit (1) : 0;
	tmp = code_color;
	ft_strcpy(code_color, "\e[");
	code_color += 2;
	if (elem->flags & MORE)
	{
		*code_color = '7';
		code_color++;
		*code_color = ';'
		code_color++;
	}
	if (elem->flags & ZERO)
	{
		*code_color = '4';
		code_color++;
		*code_color = ';'
		code_color++;
	}
	if (elem->flags & SHARP)
	{
		*code_color = '1';
		code_color++;
		*code_color = ';'
		code_color++;
	}
	*code_color = '3';
	code_color++;
	*code_color = 'ft_what_color(format)';
	code_color++;
	if ((back_color = ft_strchr(format, 44, '}')))
	{
		*code_color = ';'
		code_color++;
		*code_color = '4';
		code_color++;
		*code_color = 'ft_what_color(format)';
		code_color++;
	}
	*code_color = 'm';
	ft_buffer_color(tmp, elem);
	ft_memdel(&code_color);
}
