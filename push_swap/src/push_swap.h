/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:50:12 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 218:59:40fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <limits.h>
# include "../libft/libft.h"

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

typedef struct s_moves
{
	int ra;
	int	rb;
	int rr;
	int rra;
	int	rrb;
	int rrr;
	int pa;
	int	pb;
	int sa;
	int sb;
}		t_moves;

void	mechanical_turk(t_stack *stack);
void	make_move(t_stack *a, t_stack *b);
void	apply_moves(t_moves moves, t_stack *a, t_stack *b);
int		ft_min(int a, int b);
int		find_cheapest_element(t_stack *a, t_stack *b);
int		ft_abs(int a);
int		calculate_moves(t_moves *moves, t_stack *a, t_stack *b, int i);
int		is_modulo_sorted(t_stack stack, int element, int position);
void	reset_moves(t_moves *moves);
void	rotate_array(int array[], int lenght, int positions, char *toward);
int		gcd(int a, int b);
void	stacks_setup(t_stack **stack_a, t_stack **stack_b, t_stack *stack);
void	put_elements(t_stack *src, t_stack *dest, size_t n);
void	copy_array(int *dest, int *src, int size);
int		*initialize_stack(int size);
void	malloc_guard(void *ptr);
void	print_stack(t_stack *stack);
void	fix_input(char **argv);
t_stack	*set_stack(char **argv);
int		check_duplicates(int *array, int size);
int		set_numbers(char **argv, int *output, int size);
int		count_numbers(char **argv);
int		is_num(char c);

#endif