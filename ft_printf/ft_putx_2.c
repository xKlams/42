/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:52:33 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/22 12:05:09 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int number)
{
	int	sign;

	sign = 0;
	if (!number)
		return (ft_putchar('0'));
	if (number < 0)
	{
		sign = 1;
		ft_putchar('-');
		number *= -1;
	}
	return (ft_putnbr_aux(number) + sign);
}

int	ft_putnbr_aux(long int number)
{
	if (!number)
		return (0);
	return (ft_putnbr_aux(number / 10) + ft_putchar('0' + number % 10));
}
