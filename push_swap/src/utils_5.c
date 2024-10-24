/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:18:23 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/24 18:54:02 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '+' || c == '-')
		return (1);
	return (0);
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
			next_num(j, &i, argv);
			if (!is_num(argv[j][i]) && argv[j][i])
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
		}
		i = 0;
	}
	return (output);
}

void	next_num(int j, int *i, char **argv)
{
	while (is_num(argv[j][*i]))
		(*i)++;
	while (argv[j][*i] == ' ')
		(*i)++;
}

void	four(t_stack *stack_a, t_stack *stack_b)
{
	put_elements(stack_a, stack_b, 1);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	fix_a(stack_a);
	group_stacks(stack_a, stack_b);
}
