# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 11:06:20 by jraymond          #+#    #+#              #
#    Updated: 2018/01/17 18:39:15 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS =

PATHLIB = libft/

SRCS = analyse_format.c ft_printf.c

0BJ = $(SRCS: .c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@(cd libft && make)
		$(CC) $(FLAGS) $(SRCS) $(PATHLIB)libft.a -o $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -o $@ -c $(SRCS)

clean :
		@(cd libft make clean)
		rm -rf $(OBJ)

fclean : clean
		@(cd libft && make fclean)
		rm -rf $(NAME)

mcc : $(OBJ)
	@clear
	@(cd libft && make)
	$(CC) $(FLAGS) $(SRCS) $(PATHLIB)libft.a -o $(NAME)
	./$(NAME)	


re : 
	fclean
	make re
