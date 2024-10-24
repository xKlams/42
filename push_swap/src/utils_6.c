/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:39:00 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/25 00:27:41 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	modulo_asc_aux(t_stack stack, int min, int pos, int element)
{
	int	i;

	i = -1;
	if (element >= stack.array[stack.start + ft_modulo(min - 1, stack.size)])
	{
		if (pos == ft_modulo(min, stack.size))
			return (1);
		return (0);
	}
	while (++i < (int) stack.size + 1)
	{
		if (stack.array[stack.start + ft_modulo(min + i, stack.size)]
			< element && element
			< stack.array[stack.start + ft_modulo(min + i + 1, stack.size)])
		{
			if (pos != ft_modulo(min + i + 1, stack.size))
				return (0);
			else
				return (1);
		}
	}
	return (0);
}

int	is_modulo_sorted_asc(t_stack stack, int element, int position)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (++i < (int)stack.size)
	{
		if (stack.array[stack.start + i] < stack.array[stack.start + min])
			min = i;
	}
	if (element <= stack.array[stack.start + min])
	{
		if (position == min)
			return (1);
		return (0);
	}
	return (modulo_asc_aux(stack, min, position, element));
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
			&& i < (int)a->size)
			i++;
		if (i <= (int)a->size / 2)
			moves.ra += i;
		else
			moves.rra += ft_abs(a->size - i);
		moves.pa++;
		apply_moves(moves, a, b);
	}
	reset_moves(&moves);
	group_stacks_aux(a, b, &moves);
	reset_moves(&moves);
}

void	group_stacks_aux(t_stack *a, t_stack *b, t_moves *moves)
{
	int	i;
	int	min;

	i = -1;
	min = 0;
	while (++i < (int)a->size)
		if (a->array[a->start + i] < a->array[a->start + min])
			min = i;
	if (min < (int)a->size / 2)
		moves->ra += min;
	else
		moves->rra += ft_abs(a->size - min);
	apply_moves(*moves, a, b);
}

void	calculate_moves_aux(t_moves *moves, int *output, int j)
{
	if (moves->rra > 0 && moves->rrb > 0)
	{
		j = ft_min(moves->rra, moves->rrb);
		*output += j;
		moves->rra -= j;
		moves->rrb -= j;
		moves->rrr += j;
	}
	if (moves->ra > 0 && moves->rb > 0)
	{
		j = ft_min(moves->ra, moves->rb);
		*output += j;
		moves->ra -= j;
		moves->rb -= j;
		moves->rr += j;
	}
	*output += moves->ra;
	*output += moves->rb;
	*output += moves->rra;
	*output += moves->rrb;
}
