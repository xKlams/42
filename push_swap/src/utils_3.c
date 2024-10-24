/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:16:24 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/24 18:56:13 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_modulo(int a, int b)
{
	if (a >= 0)
		return (a % b);
	else
		return ((a + b) % b);
}

int	is_modulo_sorted(t_stack stack, int element, int position)
{
	int	i;
	int	min;
	int	output;

	output = 1;
	i = stack.start - 2;
	position += stack.start - 1;
	while (++i < position)
		stack.array[i] = stack.array[i + 1];
	stack.array[position] = element;
	i = 0;
	min = 0;
	while (++i < stack.size + 1)
		if (stack.array[stack.start -1 + i] < stack.array[stack.start -1 + min])
			min = i;
	stack.size++;
	i = -1;
	is_modulo_sorted_aux(i, stack, &output, min);
	stack.size--;
	i = position + 1;
	while (--i >= stack.start)
		stack.array[i] = stack.array[i - 1];
	return (output);
}

void	is_modulo_sorted_aux(int i, t_stack stack, int *output, int min)
{
	while (++i < stack.size - 1)
	{
		if (stack.array[stack.start - 1 + ft_modulo(min - i, stack.size)]
			> stack.array[stack.start - 1 + ft_modulo(min - i - 1, stack.size)])
			*output = 0;
		if (!*output)
			break ;
	}
}

//Set all the moves to 0
void	reset_moves(t_moves *moves)
{
	moves->pa = 0;
	moves->pb = 0;
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->sa = 0;
	moves->sb = 0;
}

// Toward must be equal to "Right" or "Left" based on rotation
void	rotate_array(int array[], int lenght, int positions, char *toward)
{
	t_rotate	idx;

	idx.i = 0;
	idx.cycles = gcd(lenght, positions);
	positions %= lenght;
	if (*toward == 'R')
		positions = lenght - positions;
	while (idx.i < idx.cycles)
	{
		idx.startele = array[idx.i];
		idx.curridx = idx.i;
		while (1)
		{
			idx.nextidx = (idx.curridx + positions) % lenght;
			if (idx.nextidx == idx.i)
				break ;
			array[idx.curridx] = array[idx.nextidx];
			idx.curridx = idx.nextidx;
		}
		array[idx.curridx] = idx.startele;
		idx.i++;
	}
}
