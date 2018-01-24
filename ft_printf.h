/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:50:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/24 16:33:00 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

/*
** ----------MASK-FLAGS----------
*/

# define ZERO (1 << 0)
# define SHARP (1 << 1)
# define MINUS (1 << 2)
# define SPACE (1 << 3)
# define MORE (1 << 4)
# define PRECI (1 << 5)

/*
** ------------------------------
*/

/*
 ** ----------MASK-SIZE----------
 */

# define HH (1 << 0)
# define H (1 << 1)
# define L (1 << 2)
# define LL (1 << 3)
# define J (1 << 4)
# define Z (1 << 5)

/*
 ** -----------------------------
 */

typedef struct s_printf
{
	char	buff[500];
	int		length;
	int		i_buff;
	char	flags;
	int		width;
	int		precision;
	char	type;
	char	size;
}				t_printf;

int			ft_printf(const char *format, ...);
t_printf	ft_Read_Format(const char *format, va_list ap);
char		ft_char_is_type(char c);
void		ft_argis_str(va_list ap, t_printf *elem);
int			ft_Print_Binary(char binary);
void		ft_init_struct(t_printf *elem);
void		ft_deal_flags(t_printf *elem, const char *format);
int			ft_deal_precision(t_printf *elem, const char *format);
int			ft_deal_width(t_printf *elem, const char *format);
int			ft_deal_size(t_printf *elem, const char *format);
void		ft_handle_param(t_printf *elem, va_list ap);

#endif
