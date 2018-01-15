/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_w_p_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:44:38 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/15 17:19:37 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_deal_width(char	*format, t_printf *elem)
{
	int	index;
	int	result;

	index = 0;
	result = ft_atoi(format);
	if (elem->width > result)
		elem->width = result;
	while (format[index] <= 48 && format[index] >= 59)
		index++;
	return (index);
}

int		ft_deal_precision(char *format, t_printf *elem)
{
	int	index;
	int	result;

	index = 1;
	result = ft_itoa(format[index]);
	if (elem->precision > result)
		elem->precision = result;
	while (format[index] <= 48 && format[index] >= 59)
		index++;
	return (index);
}

int		ft_deal_size(char *format, t_printf *elem)
{
	return ();
}

int		ft_deal_flags(char *format, t_printf *elem)
{
	int		index;
	int		i;
	char	*ocu;

	index = 0;
	i = 0;
	while (elem->flags[i])
		i++;
	while (format[index] == '-' || format[index] == '+' || format[index] == '0'
				|| format[index] == '#' || format[index] == ' ')
	{
		if (!(ocu = ft_strchr(elem->flags, format[index])))
		{
			elem->flags[i] = format[index];
			i++;
		}
		ocu = NULL;
		index++;
	}
	return (index);
}
int		ft_deal_w_p_s(char	*format, t_printf *elem)
{
	int	index;

	index = 0;
	while (format[index])
	{
		if (format[index] == '.')
			index = index + ft_deal_precision(format[index], elem);
		if (format[index] < 48 && format[index] >= 59)
			index = index + ft_deal_width(format[index], elem);
		if (format[index] == '-' || format[index] == '+' || format[index] == '0'
				|| format[index] == '#' || format[index] == ' ')
			index = index + ft_deal_flags(format[index], elem);
		if (format[index] == 'h' || format[index] == 'l' || format[index] == 'j'
				|| format[index] == 'z')
			index = index + ft_deal_size(format[index], elem);
	}
}
