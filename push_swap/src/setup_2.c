/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:17:48 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/24 18:28:27 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_sign(char **argv)
{
	int	i;
	int	j;
	int	sign;

	i = 1;
	sign = 0;
	while (argv[i])
	{
		if (sign)
			error();
		j = 0;
		while (argv[i][j])
		{
			checks(argv, sign, i, j);
			j++;
		}
		i++;
	}
	if (sign)
		error();
}

void	checks(char **argv, int sign, int i, int j)
{
	if (argv[i][j] == '-' || argv[i][j] == '+')
	{
		if (sign || j > 0 && j - 1 != ' ')
			error();
		sign = 1;
	}
	if (argv[i][j] <= '9' && argv[i][j] >= '0')
		sign = 0;
	if (!is_num(argv[i][j]) && sign)
		error();
}

int	check_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	set_numbers(char **argv, int *output, int size)
{
	int			index;
	int			i;
	int			j;
	long int	atoi_out;

	i = 0;
	j = 0;
	index = 0;
	while (argv[++j])
	{
		while (argv[j][i])
		{
			if (is_num(argv[j][i]))
			{
				atoi_out = ft_long_atoi(argv[j] + i);
				if (atoi_out > INT_MAX || atoi_out < INT_MIN)
					return (EXIT_FAILURE);
				output[index++] = (int) atoi_out;
				next_num(j, &i, argv);
			}
		}
		i = 0;
	}
	return (EXIT_SUCCESS);
}
