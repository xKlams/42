/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:39:00 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/24 18:48:05 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_modulo_sorted_asc_aux(t_stack stack, int *output, int min)
{
	int	i;

	i = -1;
	while (++i < stack.size - 1)
	{
		if (stack.array[stack.start - 1 + ft_modulo(min + i, stack.size)]
			> stack.array[stack.start - 1 + ft_modulo(min + i + 1, stack.size)])
			*output = 0;
		if (!*output)
			break ;
	}
}

void	group_stacks(t_stack *a, t_stack *b)
{
	int		i;
	t_moves	moves;

	while (b->size != 0)
	{
		reset_moves(&moves);
		i = 0;
		while (!(is_modulo_sorted_asc(*a, b->array[b->start], i))
			&& i < a->size)
			i++;
		if (i <= a->size / 2)
			moves.ra += i;
		else
			moves.rra += ft_abs(a->size - i);
		moves.pa++;
		apply_moves(moves, a, b);
	}
	group_stacks_aux(a, b, moves);
	reset_moves(&moves);
}

void	group_stacks_aux(t_stack *a, t_stack *b, t_moves moves)
{
	int	i;
	int	min;

	i = -1;
	min = 0;
	while (++i < a->size)
		if (a->array[a->start + i] < a->array[a->start + min])
			min = i;
	if (min < a->size / 2)
		moves.ra += min;
	else
		moves.rra += ft_abs(a->size - min);
	apply_moves(moves, a, b);
}

void	calculate_moves_aux(t_moves *moves, int *output, int j)
{
	if (moves->rra > 0 && moves->rrb > 0)
	{
		j = ft_min(moves->rra, moves->rrb);
		output += j;
		moves->rra -= j;
		moves->rrb -= j;
		moves->rrr += j;
	}
	if (moves->ra > 0 && moves->rb > 0)
	{
		j = ft_min(moves->ra, moves->rb);
		output += j;
		moves->ra -= j;
		moves->rb -= j;
		moves->rr += j;
	}
	output += moves->ra;
	output += moves->rb;
	output += moves->rra;
	output += moves->rrb;
}

//Euclidean algorithm to compute GDC
int	gcd(int a, int b)
{
	if (a == 0)
		return (b);
	return (gcd(b % a, a));
}
