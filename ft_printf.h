/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:50:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/01/29 21:47:31 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define BUFF_SIZE 128

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

typedef struct s_overflow
{
	int			i;
	char		*data_b;
	int			flag;
}				t_overflow;

typedef struct s_printf
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		length;
	int		i_buff;
	char	flags;
	int		width;
	int		precision;
	char	type;
	char	size;
}				t_printf;

int			ft_printf(const char *format, ...);
int			ft_read_format(const char *format, va_list ap, t_printf *elem);
char		ft_char_is_type(char c);
void		ft_argis_str(va_list ap, t_printf *elem);
int			ft_print_binary(char binary);
void		ft_init_struct(t_printf *elem);
void		ft_deal_flags(t_printf *elem, const char *format);
int			ft_deal_precision(t_printf *elem, const char *format);
int			ft_deal_width(t_printf *elem, const char *format);
int			ft_deal_size(t_printf *elem, const char *format);
int			ft_handle_param(t_printf *elem, va_list ap);
int			ft_handle_unicode(t_printf *elem, va_list ap);
void		unicode_to_str(wchar_t unicode, char *str);
int			ft_howchar_add(t_printf *elem, int len);
void		ft_addstr_no_minus(t_printf *elem, char *str, int nb_c_add);
void		ft_addstr_with_minus(t_printf *elem, char *str, int nb_c_add);
void		ft_handle_overflow(t_printf *elem, void *data, int nb, int spe);
void		ft_param_char(t_printf *elem, va_list ap);
int			ft_unicodelen(wchar_t unicode);

#endif
