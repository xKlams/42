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
	int	startEle;
	int	currIdx;
	int	nextIdx;
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

void	rotate_array(int arr[], int n, int d, char *rotation)
{
	t_rotate idx;

	idx.cycles = gcd(n,d);
    d %= n;
    if (*rotation == 'R')
        d = n - d;
    while (idx.i < idx.cycles)
	{
        idx.startEle = arr[idx.i];
        idx.currIdx = idx.i;
        while (1) {
            idx.nextIdx = (idx.currIdx + d) % n;
            if (idx.nextIdx == idx.i)
                break;
            arr[idx.currIdx] = arr[idx.nextIdx];
            idx.currIdx = idx.nextIdx;
        }
        arr[idx.currIdx] = idx.startEle;
		idx.i++;
    }
}

int main() {
    int arr[] = {6, 5, 4, 2, 1, 0};
    int n = 6;
    int d = 1;
    t_stack stack;

    stack.array = (int *)malloc(6);
    stack.array[0] = 6;
    stack.array[1] = 5;
    stack.array[2] = 4;
    stack.array[3] = 2;
    stack.array[4] = 1;
    stack.array[5] = 0;
    stack.size = n - 1  ;
    stack.start = 1;
    // printf("\n");

    print_array(stack.array + stack.start   , stack.size);
    rotate_array(stack.array + stack.start, stack.size, 2, "L");
    print_array(stack.array + stack.start   , stack.size);
    printf("is it still sorted? %d\n", is_modulo_sorted(stack, 3, 5));
    print_array(stack.array + stack.start   , stack.size);
    return 0;
}

