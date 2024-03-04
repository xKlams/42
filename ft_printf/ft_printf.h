/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:44:42 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/23 06:11:21 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_print_argument(const char string, va_list arguments);
int	ft_printf(const char *string, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_put_pointer(void *pointer);
int	hex(unsigned long int number, const char *base);
int	ft_put_hex_aux(unsigned long int number, const char *base);
int	ft_putnbr(long int number);
int	ft_putnbr_aux(long int number);

#endif