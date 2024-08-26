/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:28:49 by fde-sist          #+#    #+#             */
/*   Updated: 2024/08/26 17:51:40 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"
#include <stdio.h>

void	change_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	destroy(t_mlx_win *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

//arrowup = 65362, arrowdown =  65364, right 65363, left 65361

int	key_press_handler(int keycode, t_mlx_win *vars)
{
	if (keycode == 65307)
		destroy(vars);
	if (keycode == 65362)
		change_position("up", vars);
	if (keycode == 65364)
		change_position("down", vars);
	if (keycode == 65363)
		change_position("right", vars);
	if (keycode == 65361)
		change_position("left", vars);
	return (0);
}

void	change_position(char *direction, t_mlx_win *vars)
{
	float	x_shift;
	float	y_shift;

	x_shift = 0;
	y_shift = 0;
	if (*direction == 'u')
		y_shift = -ARROW_SENSITIVITY;
	else if (*direction == 'd')
		y_shift = ARROW_SENSITIVITY;
	else if (*direction == 'r')
		x_shift = ARROW_SENSITIVITY;
	else if (*direction == 'l')
		x_shift = -ARROW_SENSITIVITY;
	info_handler(0, x_shift, y_shift, vars);
}

void	info_handler(float scale, float x_shift, float y_shift, t_mlx_win *vars)
{
	static t_info	info;

	if (info.scale == 0)
		info.scale = 1;
	if (scale != 0)
		info.scale *= scale;
	info.x_shift += x_shift * info.scale * 1;
	info.y_shift += y_shift * info.scale * 1;
	printf("x_shift = %f\n", info.x_shift);
	printf("info.scale = %f\n", info.scale);
	gen_fractal(vars, info.fractal, info);
}

// mouseup = 5, mousedown = 4

int	mouse_handler(int keycode, int x, int y, t_mlx_win *vars)
{
	if (keycode == 5)
		info_handler(0.5, 0, 0, vars);
	if (keycode == 4)
		info_handler(1.5, 0, 0, vars);
}

void	hooks(t_mlx_win *vars)
{
	mlx_hook(vars->win, 17, 0, destroy, vars);
	mlx_key_hook(vars->win, key_press_handler, vars);
	mlx_mouse_hook(vars->win, mouse_handler, vars);
}

void	init(t_mlx_win *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, S_WIDTH, S_HEIGHT, "fractol");
	hooks(vars);
}

int	option(char **argv)
{
	if (!ft_strncmp(argv[1], "Mandelbrot", 11))
		return (1);
	if (!ft_strncmp(argv[1], "Julia", 6))
		return (2);
	return (0);
}

int	arg_check(int argc, char **argv)
{
	if (argc != 2 || !option(argv))
	{
		write(1, "Not enough parameters provided\n", 31);
		write(1, "Use argument \"Julia\" to generate Julia's set\n", 45);
		write(1, "Use argument \"Mandelbrot\"", 25);
		write(1, " to generate Mandelbrot set\n", 28);
		exit(1);
	}
	return (option(argv));
}
