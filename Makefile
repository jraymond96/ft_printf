# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 18:29:20 by jraymond          #+#    #+#              #
#    Updated: 2018/02/14 19:24:18 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_memset.c \
	   			ft_memcpy.c \
				ft_bzero.c \
				ft_strlen.c \
				ft_strcpy.c \
				ft_strncat.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_isdigit.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strncmp.c \
				analyse_format.c \
				ft_printf.c \
				ft_print_binary.c \
				ft_check_flags.c \
				ft_handle_param.c \
				ft_handle_unicode.c \
				ft_unicode_to_str.c \
				ft_handle_overflow.c \
				ft_param_char.c	\
				ft_param_decimal.c \
				ft_ilen.c \
				ft_handle_size.c \
				ft_lltoa.c \
				ft_ulltoa.c \
				ft_padding_numbnull.c \
				ft_param_unsigned.c \
				ft_param_percent.c \
				ft_abs.c \
				ft_param_octal.c \
				ft_ulltoa_base.c \
				ft_param_hexa.c \
				ft_param_address.c \
				ft_strcchr.c \
				ft_param_color.c \
				ft_param_binary.c \
				ft_param_n.c \
				ft_padd_numposi_nega.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $^

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
