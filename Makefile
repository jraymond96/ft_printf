# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 18:29:20 by jraymond          #+#    #+#              #
#    Updated: 2018/02/02 17:30:13 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_strlen.c \
				ft_memccpy.c \
				ft_putstr.c \
				ft_putchar.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strnstr.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_strjoin_free.c \
				ft_strdup_free.c \
				ft_atoi_firstnbr.c \
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
				ft_param_unsigned.c

OBJ = $(SRCS:.c=.o)

all : $(NAME) cp

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $^

cp :
	cp libftprintf.a ~/curqui_test

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
