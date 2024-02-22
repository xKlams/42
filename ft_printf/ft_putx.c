/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:44:05 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/22 10:56:22 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(0, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i = 0;

    while(str[i])
        i += ft_putchar(str[i]);
    return (i);
}

int ft_put_pointer(void *pointer)
{
    int i = 0;
    
    if (!pointer)
        return (ft_putstr("nil"));
    i += ft_putstr("0x");
    return (i + ft_put_hex((unsigned long int) pointer, "0123456789abcdef"));
}

int ft_put_hex(unsigned long int number, char *base)
{
    if (!number)
        return (ft_putchar('0'));
    return (ft_put_hex_aux(number, base));
}

int ft_put_hex_aux(unsigned long int number, char *base)
{
    if(!number)
        return 0;
    return (ft_put_hex(number/16, base) + ft_putchar(base[number % 16]));
}
