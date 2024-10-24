/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:16:01 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/24 18:48:26 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	aux;

	aux = a->array[a->start];
	a->array[a->start] = a->array[a->start + 1];
	a->array[a->start + 1] = aux;
}

int	ft_min(int a, int b)
{
	return (a * (a <= b) + b * (a > b));
}

//Finds the element with the least amount of moves to put it in the correct spot
int	find_cheapest_element(t_stack *a, t_stack *b)
{
	t_moves	moves;
	int		i;
	int		min;
	int		min_index;
	int		aux;

	i = 0;
	min = -1;
	while (i < a->size)
	{
		reset_moves(&moves);
		aux = calculate_moves(&moves, a, b, i);
		if (min == -1 || aux < min)
		{
			min = aux;
			min_index = i;
			if (min == 1)
				break ;
		}
		i++;
	}
	return (min_index);
}

int	ft_abs(int a)
{
	return (a * (a >= 0) - a * (a < 0));
}

/*caluclates the amount of moves necessary to put the i-th element of a 
in the correct spot in b, loads moves with said moves*/
int	calculate_moves(t_moves *moves, t_stack *a, t_stack *b, int i)
{
	int	j;
	int	output;

	j = 0;
	output = 0;
	if (i <= a->size / 2)
		moves->ra += i;
	else
		moves->rra += ft_abs(a->size - i);
	while (!(is_modulo_sorted(*b, a->array[a->start + i], j)) && j < b->size)
		j++;
	if (j <= b->size / 2)
		moves->rb += j;
	else
		moves->rrb += ft_abs(b->size - j);
	moves->pb += 1;
	output += moves->pb;
	calculate_moves_aux(moves, &output, j);
	return (output);
}
