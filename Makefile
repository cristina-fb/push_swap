# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 10:28:47 by crisfern          #+#    #+#              #
#    Updated: 2021/09/28 13:58:03 by crisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = 
LIBFT = libft.a

LIBFT_DIR = ./libft/

SRC_DIR = ./src/

HEADER = push_swap.h

SRC = push_swap.c ./src/push.c ./src/swap.c ./src/rotate.c ./src/rrotate.c ./src/list.c ./src/find_in_list.c ./src/sort.c ./src/utilities.c

OBJ = $(SRC:.c=.o)

all: make_libft $(NAME)

make_libft:
	make all -C $(LIBFT_DIR)

$(NAME): $(SRC_DIR)$(HEADER) $(SRC_DIR)$(SRC) $(LIBFT_DIR)$(LIBFT)
	$(CC) $(CFLAGS) $(SRC_DIR)$(SRC) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all fclean clean make_libft
