/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:28:49 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/03 16:44:11 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"

void	change_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//TODO protect malloc
int	destroy(t_mlx_win *vars)
{
	if (vars)
	{
		if (vars->mlx)
		{
			if (vars->win)
				mlx_destroy_window(vars->mlx, vars->win);
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
		}
		vars = NULL;
		exit(0);
	}
	return (0);
}

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
	if (keycode == 'c' || keycode == 'C')
		info_handler((float [3]){0, 0, 0}, 1, (float [3]){0, 0, 0}, vars);
	return (0);
}

void	change_color(t_mlx_win *vars, t_info info, int flag)
{
	static int	rand_seed;
	int			color_seed;
	static int	color;

	if (!color)
		color = STD_COLOR;
	if (flag)
	{
		srand(rand_seed++);
		color_seed = rand() % 256;
		color = (color_seed + (color_seed << 8) + (color_seed << 16));
	}
	gen_fractal(vars, info, color);
}

void	change_position(char *direction, t_mlx_win *vars)
{
	float	shift[3];

	shift[0] = 0;
	shift[1] = 0;
	shift[2] = 0;
	if (*direction == 'u')
		shift[1] = -ARROW_SPEED;
	else if (*direction == 'd')
		shift[1] = ARROW_SPEED;
	else if (*direction == 'r')
		shift[0] = ARROW_SPEED;
	else if (*direction == 'l')
		shift[0] = -ARROW_SPEED;
	info_handler(shift, 0, (float [3]){0, 0, 0}, vars);
}

void	info_handler(float params[3], int f_color, float setup[3], t_mlx_win *vars)
{
	static t_info	info;
	static int		flag;

	if (!flag)
	{
		info.c.real = setup[0];
		info.c.imag = setup[1];
		info.fractal = (int) setup[2];
		flag = 1;
	}
	if (info.scale == 0)
		info.scale = 1;
	if (params[2] != 0)
		info.scale *= params[2];
	info.x_shift += params[0] * info.scale;
	info.y_shift += params[1] * info.scale;
	change_color(vars, info, f_color);
}
