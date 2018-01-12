/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:50:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/12 20:43:16 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_printf
{
	char	buff[500];
	int		length;
	int		i_buff;
	char	flags;
	int		width;
	char	type;
}				t_printf;

int			ft_printf(const char *format, ...);
t_printf	ft_readformat(const char *format, va_list ap);
int			ft_analyse_speconversion(t_printf *elem, const char *format);
char		ft_char_is_type(char c);
void		ft_argis_str(va_list ap, t_printf *elem);

#endif
