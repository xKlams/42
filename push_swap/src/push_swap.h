/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:54:44 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/25 11:41:57 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	*array;
	int	start;
	int	dim;
}		t_stack;

typedef struct s_rotate
{
	int	cycles;
	int	startele;
	int	curridx;
	int	nextidx;
	int	i;
}		t_rotate;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	pb;
	int	sa;
	int	sb;
}		t_moves;

int		is_num(char c);
int		count_numbers(char **argv);
void	next_num(int j, int *i, char **argv);
void	four(t_stack *stack_a, t_stack *stack_b);
void	leq_five(t_stack *stack_a, t_stack *stack_b);
void	mechanical_turk(t_stack *stack);
void	free_stack(t_stack *stack);
int		gcd(int a, int b);
void	fix_input(char **argv);
int		already_sorted(int *arr, int size);
t_stack	*set_stack(char **argv);
void	error(void);
void	check_sign(char **argv);
void	checks(char **argv, int *sign, int i, int j);
int		check_duplicates(int *array, int size);
int		set_numbers(char **argv, int *output);
void	fix_a(t_stack *a);
void	make_move(t_stack *a, t_stack *b);
void	put_times(char *str, int times);
void	apply_moves(t_moves moves, t_stack *a, t_stack *b);
void	put_moves(t_moves *moves);
void	sa(t_stack *a);
int		ft_min(int a, int b);
int		find_cheapest_element(t_stack *a, t_stack *b);
int		ft_abs(int a);
int		calculate_moves(t_moves *moves, t_stack *a, t_stack *b, int i);
int		ft_modulo(int a, int b);
int		modulo_aux(t_stack stack, int min, int element);
int		modulo_sorted_pos(t_stack stack, int element);
void	reset_moves(t_moves *moves);
void	rotate_array(int array[], int lenght, int positions, char *toward);
void	stacks_setup(t_stack **stack_a, t_stack **stack_b, t_stack *stack);
void	put_elements(t_stack *src, t_stack *dest, size_t n);
void	copy_array(int *dest, int *src, int size);
int		*initialize_stack(int size);
void	malloc_guard(void *ptr);
int		modulo_asc_aux(t_stack stack, int min, int element);
int		modulo_sorted_asc(t_stack stack, int element);
void	group_stacks(t_stack *a, t_stack *b);
void	group_stacks_aux(t_stack *a, t_stack *b, t_moves *moves);
void	calculate_moves_aux(t_moves *moves, int *output, int j);

#endif