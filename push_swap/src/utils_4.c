/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:16:43 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/24 18:43:40 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Initializes stacks and puts 2 elements of sack_a into b
void	stacks_setup(t_stack **stack_a, t_stack **stack_b, t_stack *stack)
{
	(*stack_a) = (t_stack *)malloc(sizeof(t_stack));
	malloc_guard(*stack_a);
	(*stack_b) = (t_stack *)malloc(sizeof(t_stack));
	malloc_guard(*stack_b);
	(*stack_a)->array = initialize_stack(stack->size);
	(*stack_a)->start = 0;
	(*stack_a)->size = stack->size;
	(*stack_b)->array = initialize_stack(stack->size);
	(*stack_b)->start = stack->size;
	(*stack_b)->size = 0;
	(*stack_b)->dim = stack->size;
	copy_array((*stack_a)->array, stack->array, stack->size);
}

/*This function takes stack src, and stack dest, it puts the first n elements
 of stack src into stack dest, Like multiple pb*/
void	put_elements(t_stack *src, t_stack *dest, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest->array[dest->start - 1 - i] = src->array[src->start + i];
		i++;
	}
	src->size -= n;
	src->start += n;
	dest->size += n;
	dest->start -= n;
}

void	copy_array(int *dest, int *src, int size)
{
	while (size--)
		dest[size] = src[size];
}

int	*initialize_stack(int size)
{
	int	*output;

	output = (int *)malloc(size * sizeof(int));
	malloc_guard(output);
	return (output);
}

void	malloc_guard(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("Memory can't be allocated", 2);
		exit(1);
	}
}
