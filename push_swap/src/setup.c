/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:05:55 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/25 10:44:08 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Turns spaces variant into standard spaces
void	fix_input(char **argv)
{
	int	i;
	int	j;	

	j = -1;
	i = -1;
	while (argv[++j])
	{
		while (argv[j][++i])
			if (argv[j][i] <= 13 && argv[j][i] >= 9)
				argv[j][i] = ' ';
		i = -1;
	}
}

int	already_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

//Sets stack starting values
t_stack	*set_stack(char **argv)
{
	t_stack	*output;
	int		size;

	size = count_numbers(argv);
	if (!size)
		error();
	check_sign(argv);
	output = (t_stack *)malloc(sizeof(t_stack));
	output->array = (int *)malloc(sizeof(int) * size);
	output->size = size;
	if (set_numbers(argv, output->array)
		|| check_duplicates(output->array, output->size))
	{
		free(output->array);
		free(output);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (already_sorted(output->array, output->size))
	{
		free_stack(output);
		exit(1);
	}
	return (output);
}
