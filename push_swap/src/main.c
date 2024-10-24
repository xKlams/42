/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:48:14 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/23 00:39:08 fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (EXIT_FAILURE);
	fix_input(argv);
	stack = set_stack(argv);
	print_stack(stack);
	mechanical_turk(stack);
	return (EXIT_SUCCESS);
}

//Main Soritng function
void	mechanical_turk(t_stack *stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stacks_setup(&stack_a, &stack_b, stack);
	print_stack(stack_a);
	print_stack(stack_b);
	//TODO add sorting until 3 elements in a are left
	while (stack_a->size != 3)
	{
		make_move(stack_a, stack_b);
	}
	print_stack(stack_a);
	print_stack(stack_b);
}

void	make_move(t_stack *a, t_stack *b)
{
	int 	element_index;
	t_moves	moves;

	element_index = find_cheapest_element(a, b);
	printf("choesen element = %d\n index = %d\n", a->array[a->start + element_index], element_index);
	reset_moves(&moves);
	calculate_moves(&moves, a, b, element_index);
	printf("stack a = ");
	print_stack(a);
	printf("stack b = ");
    print_stack(b);
	apply_moves(moves, a, b);
}

void	apply_moves(t_moves moves, t_stack *a, t_stack *b)
{
	int	aux;
	if (moves.ra > 0 && moves.rb > 0)
	{
		aux = ft_min(moves.ra, moves.rb);
		rotate_array(a->array + a->start, a->size, aux, "R");
		rotate_array(b->array + b->start, b->size, aux, "R");
		moves.ra -= aux;
		moves.rb -= aux;
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	}
	if (moves.rra > 0 && moves.rrb > 0)
	{
		aux = ft_min(moves.ra, moves.rb);
		rotate_array(a->array + a->start, a->size, aux, "L");
		rotate_array(b->array + b->start, b->size, aux, "L");
		moves.rra -= aux;
		moves.rrb -= aux;
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
	}
	if (moves.rra > 0)
	{
		print_stack(a);
		rotate_array(a->array + a->start, a->size, moves.rra, "R");
		printf("ma sta merda ha ruotato di %d?\n", moves.rra);
		print_stack(a);
		moves.rra -= moves.rra;
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	if (moves.rrb > 0)
	{
		rotate_array(b->array + b->start, b->size, moves.rrb, "R");
		moves.rrb -= moves.rrb;
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	if (moves.ra > 0)
	{
		rotate_array(a->array + a->start, a->size, moves.ra, "L");
		moves.ra -= moves.ra;
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	if (moves.rb > 0)
	{
		rotate_array(b->array + b->start, b->size, moves.rb, "L");
		moves.rb -= moves.rb;
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	put_elements(a, b, 1);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

int	ft_min(int a, int b)
{
	return (a * (a >= b) + b * (a < b));
}

//Finds the element with the least amount of moves to put it in the correct spot
int	find_cheapest_element(t_stack *a, t_stack *b)
{
	t_moves moves;
	int 	i;
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
	int j;
	int	output;

	j = 0;
	output = 0;
	if (i <= a->size / 2)
		moves->ra += i;
	else
		moves->rra += ft_abs(a->size - i);
	while (!(is_modulo_sorted(*b,a->array[a->start + i], j)) && j < b->size)
		j++;
	if (j <= b->size / 2)
		moves->rb += j;
	else
		moves->rrb += ft_abs(b->size - j);
	moves->pb += 1;
	output += moves->pb;
	if (moves->rra > 0 && moves->rrb > 0)
	{
		j = ft_min(moves->rra, moves->rrb);
		output +=j;
		moves->rra -= j;
		moves->rrb -= j;
		moves->rrr += j;
	}
	if (moves->ra > 0 && moves->rb > 0)
	{
		j = ft_min(moves->ra, moves->rb);
		output +=j;
		moves->ra -= j;
		moves->rb -= j;
		moves->rr += j;
	}
	output += moves->ra;
	output += moves->rb;
	output += moves->rra;
	output += moves->rrb;
	return (output);
}

int ft_modulo(int a, int b)
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
    int output;

    output = 1;
	i = stack.start - 2;
    position += stack.start - 1;
	while (++i < position )
		stack.array[i] = stack.array[i + 1];
	stack.array[position] = element;
	i = 0;
	min = 0;
	while (++i < stack.size + 1)
		if (stack.array[stack.start -1 + i] < stack.array[stack.start -1 + min])
			min = i;
    stack.size++;
	i = -1;
	while (++i < stack.size - 1)
    {
        if (stack.array[stack.start-1 + ft_modulo(min - i, stack.size)] > stack.array[stack.start-1 + ft_modulo(min - i - 1, stack.size)])
            output = 0;
    }
    stack.size--;
    i = position + 1;
    while (--i >= stack.start)
        stack.array[i] = stack.array[i - 1];
	return (output);
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
	t_rotate idx;

	idx.i = 0;
	idx.cycles = gcd(lenght, positions);
	positions %= lenght;
	if (*toward == 'R')
		positions = lenght - positions;
	while (idx.i < idx.cycles)
	{
		idx.startEle = array[idx.i];
		idx.currIdx = idx.i;
		while (1) {
			idx.nextIdx = (idx.currIdx + positions) % lenght;
			if (idx.nextIdx == idx.i)
				break;
			array[idx.currIdx] = array[idx.nextIdx];
			idx.currIdx = idx.nextIdx;
		}
		array[idx.currIdx] = idx.startEle;
		idx.i++;
	}
}

//Euclidean algorithm to compute GDC
int	gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}


//Initializes stacks and puts 2 elements of sack_a into b
void	stacks_setup(t_stack **stack_a, t_stack **stack_b, t_stack *stack)
{
	(*stack_a) = (t_stack *)malloc(sizeof(t_stack));
	(*stack_b) = (t_stack *)malloc(sizeof(t_stack));
	(*stack_a)->array = initialize_stack(stack->size);
	(*stack_a)->start = 0;
	(*stack_a)->size = stack->size;
	(*stack_b)->array = initialize_stack(stack->size);
	(*stack_b)->start = stack->size;
	(*stack_b)->size = 0;
	(*stack_b)->dim = stack->size;
	copy_array((*stack_a)->array, stack->array, stack->size);
	put_elements(*stack_a, *stack_b, 2);
	ft_putstr_fd("pb\npb\n", STDOUT_FILENO);
}

/*This function takes stack src, and stack dest, it puts the first n elements of stack src into stack dest
Like multiple pb*/
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
	// malloc_guard(output);
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
