
#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef S_WIDTH
#  define S_WIDTH 1080
# endif
# ifndef S_HEIGHT
#  define S_HEIGHT 720
# endif
# ifndef ARROW_SENSITIVITY
#  define ARROW_SENSITIVITY 0.5
# endif

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx_win
{
	void	*mlx;
	void	*win;
}				t_mlx_win;

typedef struct s_complex
{
	float	real;
	float	imag;
}				t_complex;

typedef struct s_info
{
	float	x_shift;
	float	y_shift;
	float	scale;
	int		fractal;
}				t_info;

void	change_pixel(t_data *data, int x, int y, int color);
int		destroy(t_mlx_win *vars);
int		key_press_handler(int keycode, t_mlx_win *vars);
void	change_position(char *direction, t_mlx_win *vars);
void	info_handler(float scale, float x_shift, float y_shift, t_mlx_win *vars);
int		mouse_handler(int keycode, int x, int y, t_mlx_win *vars);
void	hooks(t_mlx_win *vars);
void	init(t_mlx_win *vars);
int		option(char **argv);
int		arg_check(int argc, char **argv);
void	change_image_color(t_data *img, int cos[2], t_info i);
void	m(t_complex *crd, int cos[2], t_complex r, t_data *img);
float	square(float num);
float	norm(float x, float y);
void	gen_fractal(t_mlx_win *vars, int choice, t_info info);

#endif
