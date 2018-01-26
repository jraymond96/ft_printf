# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 11:06:20 by jraymond          #+#    #+#              #
#    Updated: 2018/01/26 20:34:15 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS =

HEADER = ft_printf.h

PATHLIB = libft/

SRCS = analyse_format.c ft_printf.c ft_Print_Binary.c ft_Check_Flags.c ft_handle_param.c

0BJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		make -C libft
		$(CC) $(FLAGS) libft/libft.a $(SRCS)

%.o : %.c
		$(CC) $(FLAGS) -o $@ -c $^

clean :
		make -C libft clean
		rm -rf $(OBJ)

fclean : clean
		make -C libft fclean
		rm -rf $(NAME)

mcc : $(OBJ) $(HEADER)
	@clear
	make -C libft
	$(CC) $(FLAGS) libft/libft.a $(SRCS)
	./a.out


re : 
	make fclean
	make
