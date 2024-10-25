/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:53:34 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/25 10:58:41 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
	{
		error();
		return (EXIT_FAILURE);
	}
	fix_input(argv);
	stack = set_stack(argv);
	mechanical_turk(stack);
	return (EXIT_SUCCESS);
}

void	leq_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->array[0] > stack_a->array[1])
		{
			sa(stack_a);
			ft_putstr_fd("sa\n", 1);
		}
	}
	else if (stack_a->size == 3)
		fix_a(stack_a);
	else if (stack_a->size == 4)
		four(stack_a, stack_b);
	else if (stack_a->size == 5)
	{
		put_elements(stack_a, stack_b, 2);
		ft_putstr_fd("pb\npb\n", STDOUT_FILENO);
		if (stack_b->array[0] < stack_b->array[1])
		{
			sa(stack_b);
			ft_putstr_fd("sb\n", 1);
		}
		fix_a(stack_a);
		group_stacks(stack_a, stack_b);
	}
		free_stack(stack_a);
		free_stack(stack_b);
}

//Main Soritng function
void	mechanical_turk(t_stack *stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stacks_setup(&stack_a, &stack_b, stack);
	free_stack(stack);
	if (stack_a->size <= 5)
	{
		leq_five(stack_a, stack_b);
		return ;
	}
	put_elements(stack_a, stack_b, 2);
	ft_putstr_fd("pb\npb\n", STDOUT_FILENO);
	while (stack_a->size != 3)
		make_move(stack_a, stack_b);
	fix_a(stack_a);
	group_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

//Euclidean algorithm to compute GDC
int	gcd(int a, int b)
{
	if (a == 0)
		return (b);
	return (gcd(b % a, a));
}
