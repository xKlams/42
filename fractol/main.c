/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:51:28 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/10 15:53:38 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx_win		vars;
	int				fractal_choice;

	fractal_choice = arg_check(argc, argv);
	init(&vars);
	if (fractal_choice == 'j')
	{
		i_handler((float [3]){0, 0, 0},
			0, (float [3]){ft_atof(argv[2]),
			ft_atof(argv[3]), (float) fractal_choice}, &vars);
	}
	else
		i_handler((float [3]){0, 0, 0},
			0, (float [3]){0, 0, (float) fractal_choice}, &vars);
	mlx_loop(vars.mlx);
}
