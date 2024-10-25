/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:16:24 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/25 11:07:09 by fde-sist         ###   ########.fr       */
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

int	modulo_aux(t_stack stack, int min, int pos, int element)
{
	int	i;

	i = -1;
	if (element >= stack.array[stack.start + ft_modulo(min + 1, stack.size)])
	{
		if (pos == ft_modulo(min + 1, stack.size))
			return (1);
		return (0);
	}
	while (++i < stack.size + 1)
	{
		if (stack.array[stack.start + ft_modulo(min - i, stack.size)]
			< element && element
			< stack.array[stack.start + ft_modulo(min - i - 1, stack.size)])
		{
			if (pos != ft_modulo(min - i, stack.size))
				return (0);
			else
				return (1);
		}
	}
	return (0);
}

int	is_modulo_sorted(t_stack stack, int element, int position)
{
	int	i;
	int	min;
	
	i = 0;
	min = 0;
	while (++i < stack.size)
	{
		if (stack.array[stack.start + i] < stack.array[stack.start + min])
			min = i;
	}
	if (element <= stack.array[stack.start + min])
	{
		if (position == ft_modulo(min + 1, stack.size))
			return (1);
		return (0);
	}
	return (modulo_aux(stack, min, position, element));
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
