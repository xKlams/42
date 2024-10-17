/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:50:12 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 18:57:38 by fde-sist         ###   ########.fr       */
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
    size_t  size;
    int     *array;
}   t_stack;

typedef struct s_llist
{
    int num;
    struct s_llist *next;
    struct s_llist *prev;
} t_llist;

void	    fix_input(char **argv);
t_stack	    *set_stack(char **argv);
void	mechanical_turk(t_stack *stack);
void	list_add_end(t_llist *start, int num);
void	list_add_first(t_llist *list, int num);
void	malloc_guard(void *ptr);
void	list_del_num(t_llist *list, int num);
void	list_setup(t_llist *stack_a, t_llist *stack_b);
int 		count_numbers(char **argv);
int 		is_num(char c);
int		    set_numbers(char **argv, int *output, int size);
void	    print_stack (t_stack *stack);
int	        check_duplicates(int *array, int size);

#endif