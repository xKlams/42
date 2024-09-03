/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:32:25 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/03 16:30:59 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define S_WIDTH 1080
# define S_HEIGHT 720
# define ESC_ITER 100
# define ESC_NORM 100
# define ARROW_SPEED 0.5
# define STD_COLOR 0x00FFFFFF

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
	double	real;
	double	imag;
}				t_complex;

typedef struct s_info
{
	float		x_shift;
	float		y_shift;
	float		scale;
	int			fractal;
	t_complex	c;
}				t_info;

void	change_image_color(t_data *img, t_info i);
void	julia(t_complex *crd, t_info i, t_data *img, int color);
void	mandelbrot(t_complex *crd, t_complex r, t_data *img, int color);
void	gen_fractal(t_mlx_win *vars, t_info info, int color);
float	norm(float x, float y);
int		int_max(int a, int b);
float	ft_atof(const char *nptr);
int		mouse_handler(int keycode, int x, int y, t_mlx_win *vars);
void	hooks(t_mlx_win *vars);
void	init(t_mlx_win *vars);
int		option(char **argv, int argc);
int		arg_check(int argc, char **argv);
void	change_pixel(t_data *data, int x, int y, int color);
int		destroy(t_mlx_win *vars);
int		key_press_handler(int keycode, t_mlx_win *vars);
void	change_position(char *direction, t_mlx_win *vars);
void	info_handler(float params[3], int f_color, float setup[3], t_mlx_win *vars);

#endif
