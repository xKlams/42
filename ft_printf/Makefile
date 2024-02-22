# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 10:53:01 by fde-sist          #+#    #+#              #
#    Updated: 2024/02/22 12:28:41 by fde-sist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome del progetto
NAME = printf.a

# Compilatore e opzioni
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Lista dei file sorgente
SRC_FILES = ft_printf.c \
			ft_putx.c \
			ft_putx_2.c \

# Costruzione della lista di oggetti
OBJ_FILES = $(SRC_FILES:.c=.o)

# Regole
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
