/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:14:30 by fde-sist          #+#    #+#             */
/*   Updated: 2024/08/26 17:51:25 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"
#include <stdio.h>

void	change_image_color(t_data *img, int cos[2], t_info i)
{
	int				iter;
	t_complex		crd;
	float			x_aux;
	t_complex		r;

	crd.real = -S_WIDTH / 2;
	crd.imag = -S_HEIGHT / 2;
	r.real = crd.real / (S_WIDTH / 2) * 1.235 * i.scale - 2 + i.x_shift;
	while (crd.real < S_WIDTH / 2)
	{
		crd.imag = -S_HEIGHT / 2;
		r.imag = crd.imag / (S_HEIGHT / 2) * i.scale * 1.12 + i.y_shift;
		while (crd.imag < S_HEIGHT / 2)
		{
			m(&crd, cos, r, img);
			r.imag = crd.imag / (S_HEIGHT / 2) * 1.12 * i.scale + i.y_shift;
		}
		crd.real++;
		r.real = crd.real / (S_WIDTH / 2) * 1.235 * i.scale - 2 + i.x_shift ;
	}
}

void	m(t_complex *crd, int cos[2], t_complex r, t_data *img)
{
	int			iter;
	float		x_aux;
	t_complex	c;

	c.real = 0;
	c.imag = 0;
	iter = 0;
	while (iter < cos[1] && norm(c.real, c.imag) <= cos[0])
	{
		x_aux = square(c.real) - square(c.imag) + r.real;
		c.imag = c.imag * c.real * 2 + r.imag;
		c.real = x_aux;
		iter++;
	}
	change_pixel(img, crd->real + S_WIDTH / 2,
		crd->imag + S_HEIGHT / 2, ((float) iter / cos[1] * 0x00FFFFFF));
	crd->imag++;
}
//z^2 + c = (x^2 - y^2 + x') + i(2xy + y')

float	square(float num)
{
	return (num * num);
}

float	norm(float x, float y)
{
	return (x * x + y * y);
}

void	gen_fractal(t_mlx_win *vars, int choice, t_info info)
{
	t_data	img;
	int		costraint[2];

	costraint[0] = 100;
	costraint[1] = 100;
	img.img = mlx_new_image(vars->mlx, S_WIDTH, S_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	change_image_color(&img, costraint, info);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
}
