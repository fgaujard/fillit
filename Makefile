# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 16:26:20 by fgaujard          #+#    #+#              #
#    Updated: 2019/03/07 15:19:15 by fgaujard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -g
MAKE = make
NAME = fillit
SRC = main.c\
	read_file.c\
	count_tetri.c\
	fill_valid_tetri.c\
	verif_malloced_tetri.c\
	parse.c\
	ft_map.c\
	ft_solver.c

OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

$(NAME) : $(OBJ)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) libft/libft.a

%.o: %.c lib
	$(CC) -c $(CC_FLAGS) $(SRC) -I libft

clean : libclean
	rm -f $(OBJ)

fclean : clean libfclean
	rm -f $(NAME)

lib :
	make -C libft/

libclean :
	make -C libft/ clean

libfclean : 
	make -C libft/ fclean

all : $(NAME)

re : fclean all

.PHONY: clean fclean re all
