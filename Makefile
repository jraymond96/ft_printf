# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraymond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 11:06:20 by jraymond          #+#    #+#              #
#    Updated: 2018/01/19 18:15:31 by jraymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS =

HEADER = ft_printf.h

PATHLIB = libft/

SRCS = analyse_format.c ft_printf.c ft_Print_Binary.c ft_Check_Flags.c ft_handle_param.c

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

mcc : $(OBJ) $(HEADER)
	@clear
	@(cd libft && make)
	$(CC) $(FLAGS) $(SRCS) $(PATHLIB)libft.a -o $(NAME)
	./$(NAME)	


re : 
	fclean
	make re
