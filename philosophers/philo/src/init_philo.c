/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:13:44 by fde-sist          #+#    #+#             */
/*   Updated: 2025/03/12 15:14:07 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philosophers.h"

/*
** Initializes t_philo variable, doesn't sett the process
** @returns pointer to t_philo var created
*/
t_philo	**init_philo(int argc, char **argv)
{
	t_philo		**output;
	int			number_of_philo;
	size_t		*filled_philosophers;

	if (arg_check(argc, argv))
		exit(EXIT_FAILURE);
	filled_philosophers = (size_t *) malloc(sizeof(size_t));
	*filled_philosophers = 0;
	number_of_philo = ft_atoi(argv[1]);
	output = (t_philo **)ft_calloc(sizeof(t_philo *), (number_of_philo + 1));
	output[number_of_philo] = NULL;
	set_philo(output, argv, argc, filled_philosophers);
	init_fork(output, number_of_philo);
	return (output);
}
