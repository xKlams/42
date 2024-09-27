NAME = fractol
CC = gcc
CFLAGS =  -Werror -Wall -Wextra -g

INCLUDES = -I ./mlx
LIBS = -L ./mlx ./mlx/libmlx.a -lXext -lX11 -lm

SRC = main.c \
			mlx_utils_1.c mlx_utils_2.c mlx_utils_3.c \
			libft_functions/ft_strncmp.c generate_fractal.c math_utils.c

OBJ = $(SRC:.c=.o)

MLX_LIB = ./mlx/libmlx.a

all: $(NAME)

$(MLX_LIB):
	make -C ./mlx

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C ./mlx clean
	rm -f */$(OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
