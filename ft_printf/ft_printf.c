/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:27:37 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/22 12:32:03 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_argument(const char string, va_list arguments)
{
	const char	hex_l[16] = "0123456789abcdef";
	const char	hex_u[16] = "0123456789ABCDEF";

	if (string == 'c')
		return (ft_putchar(va_arg(arguments, int)));
	if (string == 's')
		return (ft_putstr(va_arg(arguments, char *)));
	if (string == 'p')
		return (ft_put_pointer (va_arg(arguments, void *)));
	if (string == 'd' || string == 'i')
		return (ft_putnbr((long int)va_arg(arguments, int)));
	if (string == 'u')
		return (ft_putnbr((long int)va_arg(arguments, unsigned int)));
	if (string == 'x')
		return (hex((unsigned long int)va_arg(arguments, unsigned int), hex_l));
	if (string == 'X')
		return (hex((unsigned long int)va_arg(arguments, unsigned int), hex_u));
	if (string == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	va_list	arguments;

	i = 0;
	va_start (arguments, string);
	while (*string)
	{
		if (*string != '%')
			i += ft_putchar(*string);
		else
			i += ft_print_argument(*(++string), arguments);
		string++;
	}
	return (i);
}
