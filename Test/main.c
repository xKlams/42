// C Program to right rotate the array by d positions
// using Juggling Algorithm
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	size_t	size;
	int		*array;
	int		start;
	size_t	dim;
}		t_stack;

typedef struct s_rotate
{
	int	cycles;
	int	startele;
	int	curridx;
	int	nextidx;
	int	i;
}		t_rotate;

// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void    print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

}

int ft_modulo(int a, int b)
{
    if (a >= 0)
        return (a % b);
    else
        return ((a + b) % b);
}

void	is_modulo_sorted_asc_aux_2(t_stack stack, int *output, int min)
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
int	modulo_aux(t_stack stack, int min, int pos, int element)
{
	int	i;

	i = -1;
    if (element <= stack.array[stack.start + min])
    {
        if (pos == ft_modulo(min + 1, stack.size))
            return (1);
        return(0);
    }
    if (element >= stack.array[stack.start + ft_modulo(min + 1, stack.size)])
    {
        if (pos == ft_modulo(min + 1, stack.size))
            return (1);
        return(0);
    }
	while (++i < stack.size + 1)
	{
        if (stack.array[stack.start + ft_modulo(min - i, stack.size)] < element && element < stack.array[stack.start + ft_modulo(min - i - 1, stack.size)])
        {
            if (pos != ft_modulo(min - i , stack.size))
                return (0);
            else
                return(1);
        }
	}
    return (0);
}
int	is_modulo_sorted(t_stack stack, int element, int position)
{
	int	i;
	int	min;
	int	output;

	output = 1;
	i = 0;
	min = 0;
	while (++i < stack.size)
	{
		if (stack.array[stack.start + i] < stack.array[stack.start + min])
			min = i;
	}
	return (modulo_aux(stack, min, position, element));
}

int	is_modulo_sorted_asc_2(t_stack stack, int element, int position)
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
	is_modulo_sorted_asc_aux_2(stack, &output, min);
	stack.size--;
	i = position + 1;
	while (--i >= stack.start)
		stack.array[i] = stack.array[i - 1];
	return (output);
}


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
void	is_modulo_sorted_aux_2(int i, t_stack stack, int *output, int min)
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
//si mette al posto position e scansa tutti quelli prima
int	is_modulo_sorted_2(t_stack stack, int element, int position)
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
	is_modulo_sorted_aux_2(i, stack, &output, min);
	stack.size--;
	i = position + 1;
	while (--i >= stack.start)
		stack.array[i] = stack.array[i - 1];
	return (output);
}



int	modulo_asc_aux(t_stack stack, int min, int pos, int element)
{
	int	i;

	i = -1;
    if (element <= stack.array[stack.start + min])
    {
        if (pos == min)
            return (1);
        return(0);
    }
    if (element >= stack.array[stack.start + ft_modulo(min - 1, stack.size)])
    {
        if (pos == ft_modulo(min, stack.size))
            return (1);
        return(0);
    }
	while (++i < stack.size + 1)
	{
        if (stack.array[stack.start + ft_modulo(min + i, stack.size)] < element && element < stack.array[stack.start + ft_modulo(min + i + 1, stack.size)])
        {
            if (pos != ft_modulo(min + i + 1, stack.size))
                return (0);
            else
                return(1);
        }
	}
    return (0);
}
int	is_modulo_sorted_asc(t_stack stack, int element, int position)
{
	int	i;
	int	min;
	int	output;

	output = 1;
	i = 0;
	min = 0;
	while (++i < stack.size)
	{
		if (stack.array[stack.start + i] < stack.array[stack.start + min])
			min = i;
	}
	return (modulo_asc_aux(stack, min, position, element));
}

int is_in(int *array, int size, int element)
{
	int i = -1;
	while(++i < size)
	{
		if (array[i] == element)
			return(1);
	}
	return (0);
}

int main() {
    int n = 6;
    int d = 1;
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->array = (int *)malloc(n);
    stack->array[0] = 2;
    stack->array[1] = 3;
    stack->array[2] = 5;
    stack->array[3] = 6;
    stack->array[4] = 8;
    stack->array[5] = 1;
    stack->size = n - 1  ;
    stack->start = 1;
    // printf("\n"

    for (int i = 0; i < 5; i++)
    {
        stack->array[0] = 2;
        stack->array[1] = 8;
        stack->array[2] = 6;
        stack->array[3] = 5;
        stack->array[4] = 4;
        stack->array[5] = 3;
        rotate_array(stack->array + stack->start, stack->size, i, "R");
        print_array(stack->array + stack->start   , stack->size);
		// printf("is it sorted? %d\n", is_modulo_sorted_asc(*stack, 4, 0));
		for(int j =0; j < 5; j++)
		// int j =0;
			for(int k=-5; k < 10; k++)
			{
				if(!is_in(stack->array + stack->start, stack->size, k))
				{
					if (is_modulo_sorted(*stack, k, j) != is_modulo_sorted_2(*stack,k,j))
					{
						printf("breaks with element = %d, position = %d\n", k,j);
						printf("new is %d\n", is_modulo_sorted(*stack, k, j));
					}
					}
			}
    }
    return 0;
}

