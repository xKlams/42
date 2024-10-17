NAME = fractol
CC = gcc
CFLAGS =  -Werror -Wall -Wextra

INCLUDES = -I ./minilibx-linux
LIBS = -L ./minilibx-linux ./minilibx-linux/libmlx.a -lXext -lX11 -lm

SRC = main.c \
			mlx_utils_1.c mlx_utils_2.c mlx_utils_3.c \
			libft_functions/ft_strncmp.c generate_fractal.c math_utils.c

OBJ = $(SRC:.c=.o)

MLX_LIB = ./minilibx-linux/libmlx.a

all: $(NAME)

$(MLX_LIB):
	make -C ./minilibx-linux

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C ./minilibx-linux clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
