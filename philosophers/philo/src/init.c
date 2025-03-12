/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:05:02 by fde-sist          #+#    #+#             */
/*   Updated: 2025/03/12 15:14:40 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philosophers.h"
#include <bits/pthreadtypes.h>

/*
** Sets up fork mutexes for philo variable
*/
void	init_fork(t_philo **philo, int number_of_philo)
{
	pthread_mutex_t	**forks;
	int				index;
	bool			**forks_avaliable;

	index = -1;
	forks = (pthread_mutex_t **)
		ft_calloc(sizeof(pthread_mutex_t *), number_of_philo);
	forks_avaliable = (bool **) ft_calloc(sizeof(bool *), number_of_philo);
	while (++index < number_of_philo)
	{
		forks_avaliable[index] = (bool *) malloc(sizeof(bool));
		*forks_avaliable[index] = true;
		forks[index] = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
		pthread_mutex_init(forks[index], NULL);
	}
	set_forks(philo, forks_avaliable, number_of_philo, forks);
	free(forks);
	free(forks_avaliable);
}

bool	are_all_digits(char *str)
{
	if (!str)
		return (false);
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}

/*
** Checks if all args are passed correctly
** @returns 1 if args are wrong, 0 otherwise
*/
int	arg_check(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc < 5 || argc > 6)
	{
		write(2, "Error: wrong number of args\n", 29);
		return (EXIT_FAILURE);
	}
	while (++index < argc)
	{
		if (ft_atoi(argv[index]) < 1 || !are_all_digits(argv[index]))
		{
			write(2, "Error: invalid parameters\n", 27);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	set_args(t_philo **output, char **argv, int argc, int index)
{
	output[index]->time_to_die = ft_atoi(argv[2]);
	output[index]->time_to_eat = ft_atoi(argv[3]);
	output[index]->time_to_sleep = ft_atoi(argv[4]);
	output[index]->number_of_meals = 0;
	output[index]->is_dead = 0;
	output[index]->is_full = 0;
	if (argc == 6)
		output[index]->number_of_meals = ft_atoi(argv[5]);
}

void	set_philo(t_philo **output, char **argv,
		int argc, size_t *filled_philosophers)
{
	int		index;
	int		number_of_philo;
	bool	*simulation_status;
	size_t	starting_time;

	number_of_philo = ft_atoi(argv[1]);
	simulation_status = (bool *) malloc(sizeof(bool));
	*simulation_status = true;
	index = -1;
	starting_time = get_time_in_ms();
	while (++index < number_of_philo)
	{
		output[index] = (t_philo *)malloc(sizeof(t_philo));
		output[index]->id = index + 1;
		output[index]->number_of_philo = number_of_philo;
		output[index]->filled_philosophers = filled_philosophers;
		output[index]->meals_eaten = 0;
		output[index]->starting_time = starting_time;
		set_args(output, argv, argc, index);
		output[index]->simulation_status = simulation_status;
		output[index]->last_meal_time = starting_time;
		output[index]->death_lock = (pthread_mutex_t *)
			malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(output[index]->death_lock, NULL);
	}
}
