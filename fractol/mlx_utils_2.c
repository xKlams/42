/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:06:19 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/23 00:57:15 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"

int	mouse_handler(int keycode, int x, int y, t_mlx_win *vars)
{
	if (keycode == 5)
		i_handler((float [3]){x, y, 1.5}, 0, (float [3]){0, 0, 0}, vars);
	if (keycode == 4)
		i_handler((float [3]){x, y, 0.5}, 0, (float [3]){0, 0, 0}, vars);
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
	if (!(vars->mlx))
	{
		perror("Failed to initialize mlx");
		exit(EXIT_FAILURE);
	}
	vars->win = mlx_new_window(vars->mlx, S_WIDTH, S_HEIGHT, "fractol");
	if (!(vars->win))
	{
		perror("Failed to initialize windows");
		exit(EXIT_FAILURE);
	}
	hooks(vars);
}

int	option(char **argv, int argc)
{
	int	len;

	if (!ft_strncmp(argv[1], "Mandelbrot", 11)
		|| !ft_strncmp(argv[1], "Burning", 8))
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", 11))
			len = 11;
		else
			len = 8;
		if (argc != 2)
		{
			write(1, "Too many parameters!\n", 21);
			write(1, "If you want to generate ", 25);
			write(1, argv[1], len);
			write(1, " don't pass any other parameter\n", 33);
			exit(1);
		}
		return ('m' * (len == 11) + 'b' * (len == 8));
	}
	if (!ft_strncmp(argv[1], "Julia", 6))
	{
		julia_output(argc);
		return ('j');
	}
	return (0);
}

void	julia_output(int argc)
{
	if (argc != 4)
	{
		write(1, "Not enough parameters provided\n", 31);
		write(1, "Provide the program with real and ", 34);
		write(1, "imaginary part of constant parameter\n", 37);
		exit(1);
	}
}
