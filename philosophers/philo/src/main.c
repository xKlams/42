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

time_t	get_time_in_ms(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

size_t	ft_min(size_t a, size_t b)
{
	return (b * (a >= b) + a * (a < b));
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
	size_t	time_to_wait;

	time_to_wait = ft_min(
			philosophers->last_meal_time - get_time_in_ms(), max_wait);
	usleep(time_to_wait);
	if (*philosophers->simulation_status
		&& get_time_in_ms() - philosophers->last_meal_time
		> philosophers->time_to_die)
	{
		pthread_mutex_lock(philosophers->death_lock);
		philosophers->is_dead = true;
		pthread_mutex_unlock(philosophers->death_lock);
		if (*philosophers->simulation_status)
		{
			pthread_mutex_lock(philosophers->put_lock);
			if (*philosophers->simulation_status)
				printf("%ld %ld is dead\n", get_time_in_ms() - philosophers->starting_time, philosophers->id);
			*philosophers->simulation_status = false;
			pthread_mutex_unlock(philosophers->put_lock);
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo	**philosophers;
	int		number_of_philo;
	int		index;

	index = -1;
	philosophers = init_philo(argc, argv);
	number_of_philo = ft_atoi(argv[1]);
	init_fork(philosophers, number_of_philo);
	while (++index < number_of_philo)
		pthread_create(&(philosophers[index]->process), NULL,
			(void *)philo_routine, philosophers[index]);
	index = -1;
	while (++index < number_of_philo)
		pthread_join((philosophers[index])->process, NULL);
}
