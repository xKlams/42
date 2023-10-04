/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:18:38 by fde-sist          #+#    #+#             */
/*   Updated: 2023/09/28 19:45:41 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	check_space_minus(char *str, int *i, int *n_minus)
{
	while (str[*i] == '+' || str[*i] == '-'
		|| (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
	{
		if (str[*i] == '-')
			(*n_minus)++;
		(*i)++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	n_minus;
	int	number;

	i = 0;
	number = 0;
	n_minus = 0;
	check_space_minus(str, &i, &n_minus);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = 10 * number + (str[i] - '0');
		else
			return (number);
		i++;
	}
	if (n_minus % 2 == 1)
		number *= -1;
	return (number);
}
