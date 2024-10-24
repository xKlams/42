/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:05:55 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/23 00:30:33 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->start;
	while (i < stack->size + stack->start)
		printf("%d ", stack->array[i++]);
	printf("\n");
}

//Turns spaces variant into standard spaces
void	fix_input(char **argv)
{
	int	i;
	int j;	

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

//Sets stack starting values
t_stack	*set_stack(char **argv)
{
	t_stack	*output;
	int	size;

	size = count_numbers(argv);
	if (size == -1)
		exit(1);
	output = (t_stack *)malloc(sizeof(t_stack));
	output->array = (int *)malloc(sizeof(int) * size);
	output->size = size;
	if (set_numbers(argv, output->array, output->size) || check_duplicates(output->array, output->size))
	{
		free(output->array);
		free(output);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (output);
}

int	check_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while(j < size)
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
	int 		j;
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
			}
			while (is_num(argv[j][i]))
				i++;
			while (argv[j][i] == ' ')
				i++;
		}
		i = 0;
	}
	return (EXIT_SUCCESS);
}

int	count_numbers(char **argv)
{
	int	output;
	int	i;
	int	j;

	i = 0;
	j = 0;
	output = 0;	
	while (argv[++j])
	{
		while (argv[j][i])
		{
			if (is_num(argv[j][i]))
			output++;
			while (is_num(argv[j][i]) )
				i++;
			while (argv[j][i] == ' ')
				i++;
			if (!is_num(argv[j][i]) && argv[j][i])
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
		}
		i = 0;
	}
	return (output);
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9' || c == '+' || c == '-');
}
