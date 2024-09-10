/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:14:30 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/10 15:50:35 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"

// s = scaled point, i = fractal info, crd = coordinates
void	set_image(t_data *img, t_info i, int color)
{
	t_complex	crd;
	t_complex	s;
	int			coeff;

	coeff = int_max(S_HEIGHT, S_WIDTH) / 2;
	crd.real = -S_WIDTH / 2;
	crd.imag = -S_HEIGHT / 2;
	s.real = crd.real / coeff * SCALE_X * i.scale + i.x_shift;
	while (crd.real < S_WIDTH / 2)
	{
		crd.imag = -S_HEIGHT / 2;
		s.imag = crd.imag / coeff * i.scale * SCALE_Y + i.y_shift;
		while (crd.imag < S_HEIGHT / 2)
		{
			if (i.fractal == 'm')
				mandelbrot(&crd, s, img, color);
			if (i.fractal == 'j')
				julia(&crd, i, img, color);
			if (i.fractal == 'b')
				burning(&crd, s, img, color);
			s.imag = crd.imag / coeff * SCALE_Y * i.scale + i.y_shift;
		}
		crd.real++;
		s.real = crd.real / coeff * SCALE_X * i.scale + i.x_shift;
	}
}

void	julia(t_complex *crd, t_info i, t_data *img, int color)
{
	int			iter;
	double		x_aux;
	int			coeff;
	t_complex	num;

	coeff = int_max(S_HEIGHT, S_WIDTH) / 2;
	iter = 0;
	num.real = crd->real / coeff * 1.235 * i.scale + i.x_shift;
	num.imag = crd->imag / coeff * 1.12 * i.scale + i.y_shift;
	while (iter < ESC_ITER && norm(num.real, num.imag) < ESC_NORM)
	{
		x_aux = pow(num.real, 2) - pow(num.imag, 2) + i.c.real;
		num.imag = num.imag * num.real * 2 + i.c.imag;
		num.real = x_aux;
		iter++;
	}
	change_pixel(img, crd->real + S_WIDTH / 2,
		crd->imag + S_HEIGHT / 2, ((float) iter / ESC_ITER * color));
	crd->imag++;
}

void	mandelbrot(t_complex *crd, t_complex s, t_data *img, int color)
{
	int			iter;
	double		x_aux;
	t_complex	c;

	c.real = 0;
	c.imag = 0;
	iter = 0;
	while (iter < ESC_ITER && norm(c.real, c.imag) <= ESC_NORM)
	{
		x_aux = pow(c.real, 2) - pow(c.imag, 2) + s.real;
		c.imag = c.imag * c.real * 2 + s.imag;
		c.real = x_aux;
		iter++;
	}
	change_pixel(img, crd->real + S_WIDTH / 2,
		crd->imag + S_HEIGHT / 2, ((float) iter / ESC_ITER * color));
	crd->imag++;
}

void	burning(t_complex *crd, t_complex s, t_data *img, int color)
{
	int			iter;
	double		x_aux;
	t_complex	c;

	c.real = 0;
	c.imag = 0;
	iter = 0;
	while (iter < ESC_ITER && norm(c.real, c.imag) <= ESC_NORM)
	{
		x_aux = pow(c.real, 2) - pow(c.imag, 2) + s.real;
		c.imag = d_abs(c.imag) * d_abs(c.real) * 2 + s.imag;
		c.real = x_aux;
		iter++;
	}
	change_pixel(img, crd->real + S_WIDTH / 2,
		crd->imag + S_HEIGHT / 2, ((float) iter / ESC_ITER * color));
	crd->imag++;
}

void	gen_fractal(t_mlx_win *vars, t_info info, int color)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, S_WIDTH, S_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	set_image(&img, info, color);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
}
