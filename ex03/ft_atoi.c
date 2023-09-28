/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:18:38 by fde-sist          #+#    #+#             */
/*   Updated: 2023/09/28 13:17:15 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int	ft_pow(int a, int b)
{
	int i;
	int num;
	
	if (b == 0)
		return (1);
	num = a;
	i = 1;
	while (i < b)
	{
		num *= a;
		i++;
	}
	return(num);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int i;
	int	n_minus;
	int number;
	int	min_i;
	int max_i;

	i = 0;
	number = 0;
	n_minus = 0;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			n_minus++;
		if (!str[i])
			return (0);
		i++;
	}
	min_i = i;
	while (str[i])
		i++;
	i--;
	max_i = i;
	while (i >= min_i)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
		number += (str[i] - '0') * ft_pow(10, (max_i - i)); 
		}else
		{
			return (number);
		}
		i--;
	}
	if (n_minus % 2 == 1)
		number *= -1;
	return (number);
}
