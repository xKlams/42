/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:51:28 by fde-sist          #+#    #+#             */
/*   Updated: 2024/08/29 01:46:51 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx_win		vars;
	int				fractal_choice;

	init(&vars);
	fractal_choice = arg_check(argc, argv);
	if (fractal_choice == 2)
	{
		info_handler((float [3]){0, 0, 0},
			fractal_choice, (float [2]){ft_atof(argv[2]),
			ft_atof(argv[3])}, &vars);
	}
	else
		info_handler((float [3]){0, 0, 0},
			fractal_choice, (float [2]){0, 0}, &vars);
	mlx_loop(vars.mlx);
}
