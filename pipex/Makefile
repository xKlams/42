# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 17:11:06 by fde-sist          #+#    #+#              #
#    Updated: 2024/10/17 11:31:03 by fde-sist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

SRC = ./src/main.c ./src/utils.c ./src/setup.c ./src/pipe.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS += -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -o $(NAME) $(OBJ) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
