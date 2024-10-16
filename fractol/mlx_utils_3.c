/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:49:56 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/16 15:14:38 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"

//info handler function
void	i_handler(float params[3], int color, float setup[3], t_mlx_win *vars)
{
	static t_info	info;
	static int		flag;
	int				coeff;

	coeff = int_max(S_HEIGHT, S_WIDTH);
	if (!flag)
		fractal_setup(&info, setup, &flag);
	if (info.scale == 0)
		info.scale = 1;
	if (f_abs(params[0]) == ARROW_SPEED
		|| f_abs(params[1]) == ARROW_SPEED || !params[0] || !params[1])
	{
		info.x_shift += params[0] * info.scale;
		info.y_shift += params[1] * info.scale;
	}
	else
	{
		params[1] -= S_HEIGHT / 2;
		params[0] -= S_WIDTH / 2;
		info.x_shift += (params[0] / coeff * SCALE_X * info.scale);
		info.y_shift += (params[1] / coeff * SCALE_Y * info.scale);
	}
	if (params[2] != 0)
		info.scale *= params[2];
	change_color(vars, info, color);
}

void	fractal_setup(t_info *info, float *setup, int *flag)
{
	(*info).c.real = setup[0];
	(*info).c.imag = setup[1];
	(*info).fractal = (int) setup[2];
	*flag = 1;
}

float	f_abs(float a)
{
	return (-a * (a < 0) + a * (a >= 0));
}

int	arg_check(int argc, char **argv)
{
	if (argc < 2 || !option(argv, argc))
	{
		write(1, "Not enough parameters provided\n", 31);
		write(1, "Use argument \"Julia\" to generate Julia's set\n", 45);
		write(1, "Use argument \"Mandelbrot\"", 25);
		write(1, " to generate Mandelbrot set\n", 28);
		write(1, "Use argument \"Burning\"", 23);
		write(1, " to generate Burning ship set\n", 31);
		exit(1);
	}
	return (option(argv, argc));
}
