/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:29:44 by fde-sist          #+#    #+#             */
/*   Updated: 2025/03/06 13:03:36 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

bool	is_dead(t_philo *philosopher)
{
	bool	output;

	pthread_mutex_lock(philosopher->death_lock);
	output = philosopher->is_dead;
	pthread_mutex_unlock(philosopher->death_lock);
	return (output);
}

void	put_with_lock(char *buffer, t_philo *philo)
{
	pthread_mutex_lock(philo->put_lock);
	if (*philo->simulation_status)
		printf(buffer, get_time_in_ms() - philo->starting_time, philo->id);
	pthread_mutex_unlock(philo->put_lock);
}

void	wait_death(t_philo *philosophers, size_t max_wait)
{
	int	time_to_wait;

	time_to_wait = max_wait;
	if ((int)max_wait > (int)(philosophers->time_to_die - (get_time_in_ms()
			- philosophers->last_meal_time)) * 1000)
		time_to_wait = (int)(philosophers->time_to_die - (get_time_in_ms()
					- philosophers->last_meal_time)) * 1000 + 1000;
	if (time_to_wait > 0)
		usleep(time_to_wait);
	pthread_mutex_lock(philosophers->put_lock);
	if (*philosophers->simulation_status
		&& get_time_in_ms() - philosophers->last_meal_time
		>= philosophers->time_to_die)
	{
		pthread_mutex_lock(philosophers->death_lock);
		philosophers->is_dead = true;
		if (*philosophers->simulation_status)
			printf("%ld %ld is dead\n", get_time_in_ms()
				- philosophers->starting_time, philosophers->id);
		*philosophers->simulation_status = false;
		pthread_mutex_unlock(philosophers->death_lock);
	}
	pthread_mutex_unlock(philosophers->put_lock);
}

void	free_philos(t_philo **philosophers, int number_of_philo)
{
	int	i;

	i = -1;
	free(philosophers[0]->put_lock);
	free(philosophers[0]->increment_meals);
	free(philosophers[0]->simulation_status);
	free(philosophers[0]->filled_philosophers);
	i = -1;
	while (++i < number_of_philo)
	{
		free(philosophers[i]->r_fork);
		free(philosophers[i]->r_fork_available);
		free(philosophers[i]->death_lock);
		free(philosophers[i]);
	}
	free(philosophers);
}

int	main(int argc, char **argv)
{
	t_philo	**philosophers;
	int		number_of_philo;
	int		index;

	index = -1;
	philosophers = init_philo(argc, argv);
	number_of_philo = ft_atoi(argv[1]);
	while (++index < number_of_philo)
		pthread_create(&(philosophers[index]->process), NULL,
			(void *)philo_routine, philosophers[index]);
	index = -1;
	while (++index < number_of_philo)
		pthread_join((philosophers[index])->process, NULL);
	free_philos(philosophers, number_of_philo);
}
