/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:51:28 by fde-sist          #+#    #+#             */
/*   Updated: 2024/08/26 17:51:52 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx_win		vars;
	unsigned char	option_choosen;
	t_data			img;
	t_info			info;

	info.fractal = 0;
	info.scale = 1;
	info.x_shift = 0;
	info.y_shift = 0;
	option_choosen = arg_check(argc, argv);
	init(&vars);
	gen_fractal(&vars, info.fractal, info);
	mlx_loop(vars.mlx);
}
