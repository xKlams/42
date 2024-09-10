/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:01:08 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/10 15:48:11 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fractol.h"

double	norm(float x, float y)
{
	return (x * x + y * y);
}

int	int_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	d_abs(double a)
{
	return (a * (a >= 0) - a * (a < 0));
}

float	ft_atof(const char *nptr)
{
	double	i;
	double	sign;
	char	*dot;

	i = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while ((*nptr >= '0' && *nptr <= '9') || *nptr == '.')
	{
		if (*nptr == '.')
			dot = (char *)(nptr++);
		else
			i = i * 10 + *(nptr++) - '0';
	}
	nptr--;
	if (dot)
		return ((float)(sign * i / pow(10, (nptr - dot))));
	return ((float)(sign * i));
}
