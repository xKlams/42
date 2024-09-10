NAME = fractol
CC = gcc
CFLAGS =  -Werror -Wall -Wextra -g

INCLUDES = -I ./mlx
LIBS = -L ./mlx ./mlx/libmlx.a -lXext -lX11 -lm

SRC = main.c \
			mlx_utils_1.c mlx_utils_2.c mlx_utils_3.c \
			libft_functions/ft_strncmp.c generate_fractal.c math_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./mlx
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

%.o: %.c
	make -C ./mlx
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C ./mlx clean
	rm -f */$(OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME)

norm:
	clear
	norminette $(SRC)

.PHONY: all clean re fclean valgrind norm
