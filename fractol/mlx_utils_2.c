/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:06:19 by fde-sist          #+#    #+#             */
/*   Updated: 2024/08/29 01:55:14 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"

int	mouse_handler(int keycode, int x, int y, t_mlx_win *vars)
{
	if (keycode == 5)
		info_handler((float [3]){0, 0, 0.5}, 0, (float [2]){0, 0}, vars);
	if (keycode == 4)
		info_handler((float [3]){0, 0, 1.5}, 0, (float [2]){0, 0}, vars);
	return (x + y);
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

int	option(char **argv, int argc)
{
	if (!ft_strncmp(argv[1], "Mandelbrot", 11))
	{
		if (argc != 2)
		{
			write(1, "Too many parameters!\n", 21);
			write(1, "If you want to generate Mandelbro", 33);
			write(1, "t don't pass any other parameter\n", 33);
			exit(1);
		}
		return (1);
	}
	if (!ft_strncmp(argv[1], "Julia", 6))
	{
		if (argc != 4)
		{
			write(1, "Not enough parameters provided\n", 31);
			write(1, "Provide the program with real and ", 34);
			write(1, "imaginary part of constant parameter\n", 37);
			exit(1);
		}
		return (2);
	}
	return (0);
}
//check if secure
int	arg_check(int argc, char **argv)
{
	if (argc < 2 || !option(argv, argc))
	{
		write(1, "Not enough parameters provided\n", 31);
		write(1, "Use argument \"Julia\" to generate Julia's set\n", 45);
		write(1, "Use argument \"Mandelbrot\"", 25);
		write(1, " to generate Mandelbrot set\n", 28);
		exit(1);
	}
	return (option(argv, argc));
}
