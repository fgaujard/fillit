# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 16:26:20 by fgaujard          #+#    #+#              #
#    Updated: 2019/01/22 14:01:08 by fgaujard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
MAKE = make
NAME = fillit
LIB =
SRC = main.c\
	read_file.c
OBJ =
INCLUDES = fillit.h

$(NAME) : $(OBJ)

$(OBJ) : $(SRC) $(INCLUDES)
	$(CC) $(CC_FLAGS) $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

all : $(NAME)

re : fclean all

.PHONY: clean fclean re all
