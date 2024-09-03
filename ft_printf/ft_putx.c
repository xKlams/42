/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:44:05 by fde-sist          #+#    #+#             */
/*   Updated: 2024/08/27 16:48:43 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_put_pointer(void *pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	return (i + hex((unsigned long int) pointer, "0123456789abcdef"));
}

int	hex(unsigned long int number, const char *base)
{
	if (!number)
		return (ft_putchar('0'));
	return (ft_put_hex_aux(number, base));
}

int	ft_put_hex_aux(unsigned long int number, const char *base)
{
	if (!number)
		return (0);
	return (ft_put_hex_aux(number / ft_strlen(base), base) + ft_putchar(base[number % ft_strlen(base)]));
}
