/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:15:40 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/25 10:44:51 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_a(t_stack *a)
{
	t_moves	moves;
	int		*arr;

	arr = a->array + a->start;
	reset_moves(&moves);
	if (arr[1] > arr[0] && arr[0] > arr[2])
		moves.rra++;
	if (arr[1] > arr[2] && arr[2] > arr[0])
	{
		moves.sa++;
		moves.ra++;
	}
	if (arr[2] > arr[0] && arr[0] > arr[1])
		moves.sa++;
	if (arr[0] > arr[2] && arr[2] > arr[1])
		moves.ra++;
	if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		moves.sa++;
		moves.rra++;
	}
	apply_moves(moves, a, a);
}

void	make_move(t_stack *a, t_stack *b)
{
	int		element_index;
	t_moves	moves;

	element_index = find_cheapest_element(a, b);
	reset_moves(&moves);
	calculate_moves(&moves, a, b, element_index);
	apply_moves(moves, a, b);
}

void	put_times(char *str, int times)
{
	while (times--)
	{
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	apply_moves(t_moves moves, t_stack *a, t_stack *b)
{
	if (moves.sa > 0)
		sa(a);
	if (moves.rr > 0)
	{
		rotate_array(a->array + a->start, a->size, moves.rr, "L");
		rotate_array(b->array + b->start, b->size, moves.rr, "L");
	}
	if (moves.rrr > 0)
	{
		rotate_array(a->array + a->start, a->size, moves.rrr, "R");
		rotate_array(b->array + b->start, b->size, moves.rrr, "R");
	}
	if (moves.rra > 0)
		rotate_array(a->array + a->start, a->size, moves.rra, "R");
	if (moves.rrb > 0)
		rotate_array(b->array + b->start, b->size, moves.rrb, "R");
	if (moves.ra > 0)
		rotate_array(a->array + a->start, a->size, moves.ra, "L");
	if (moves.rb > 0)
		rotate_array(b->array + b->start, b->size, moves.rb, "L");
	if (moves.pb > 0)
		put_elements(a, b, moves.pb);
	if (moves.pa > 0)
		put_elements(b, a, moves.pa);
	put_moves(&moves);
}

void	put_moves(t_moves *moves)
{
	put_times("sa", moves->sa);
	put_times("rrr", moves->rrr);
	put_times("rr", moves->rr);
	put_times("rb", moves->rb);
	put_times("ra", moves->ra);
	put_times("rrb", moves->rrb);
	put_times("rra", moves->rra);
	put_times("pa", moves->pa);
	put_times("pb", moves->pb);
	reset_moves(moves);
}
