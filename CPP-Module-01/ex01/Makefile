# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 17:11:06 by fde-sist          #+#    #+#              #
#    Updated: 2025/11/03 12:29:21 by fde-sist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = horde

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98


SRC_DIR = ./
OBJ_DIR = obj/
INCLUDE_DIR = ./

SRC_FILES = main.cpp Zombie.cpp zombieHorde.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
