/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:48:14 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 19:03:00 by fde-sist         ###   ########.fr       */
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
	// print_stack(stack);
	t_llist	*list;
	list = (t_llist *)malloc(sizeof(t_llist));
	list->next = NULL;
	list->prev = NULL;
	list->num = 2;
	list_add_end(list, 2);
	list_add_end(list, 3);
	while(list)
	{
		printf("%d ", list->num);
		list = list->next;
	}

	// mechanical_turk(stack);
	return (EXIT_SUCCESS);
}

void	mechanical_turk(t_stack *stack)
{
	t_llist	*stack_a;
	t_llist	*stack_b;

	// pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
}

// void	pa(t_llist stack_a, t_llist stack_b)
// {

// }

void	list_add_end(t_llist *start, int num)
{
	t_llist	*list;
	t_llist 	*aux;

	list = start;
	if (!list)
		return ;
	while (list->next != NULL)
		list = list->next;
	aux = (t_llist *) malloc(sizeof(t_llist));
	malloc_guard(aux);
	aux->prev = list;
	aux->num = num;
	aux->next = NULL;
	list->next = aux;
}

void	list_add_first(t_llist *list, int num)
{
	t_llist 	*aux;

	if (!list)
		return ;
	while (list->prev != NULL)
		list = list->prev;
	aux = (t_llist *) malloc(sizeof(t_llist));
	malloc_guard(aux);
	aux->next = list;
	aux->prev = NULL;
	aux->num = num;
	list->prev = aux;
}

void	malloc_guard(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("Memory can't be allocated", 2);
		exit(1);
	}
}

void	list_del_num(t_llist *list, int num)
{
	t_llist	*aux_prev;
	t_llist	*aux_next;

	if (list == NULL)
		return;
	if (list->num == num)
	{
		aux_prev = list->prev;
		aux_next = list->next;
		if (aux_prev)
			aux_prev->next = aux_next;
		if (aux_next)
			aux_next->prev = aux_prev;
		free(list);
		return ;
	}
	list_del_num(list->next, num);
}

void	list_setup(t_llist *stack_a, t_llist *stack_b)
{
	stack_a = (t_llist *)malloc(sizeof(t_llist));
	stack_b = (t_llist *)malloc(sizeof(t_llist));
	malloc_guard(stack_a);
	malloc_guard(stack_b);
	stack_a->prev = NULL;
	stack_a->next = NULL;
	stack_b->prev = NULL;
	stack_b->next = NULL;
}
