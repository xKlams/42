/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_eat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:13:50 by fde-sist          #+#    #+#             */
/*   Updated: 2025/03/12 14:14:10 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philosophers.h"
#include <pthread.h>

void	check_meals(t_philo *philosophers)
{
	philosophers->meals_eaten++;
	if (philosophers->number_of_meals
		&& philosophers->meals_eaten
		>= philosophers->number_of_meals)
	{
		if (!philosophers->is_full)
		{
			pthread_mutex_lock(philosophers->increment_meals);
			(*philosophers->filled_philosophers)++;
			pthread_mutex_unlock(philosophers->increment_meals);
		}
		philosophers->is_full = true;
	}
}

void	eat_and_check(t_philo *philosophers)
{
	*philosophers->r_fork_available = false;
	pthread_mutex_unlock(philosophers->r_fork);
	put_with_lock("%ld %ld has taken a fork\n", philosophers);
	put_with_lock("%ld %ld has taken a fork\n", philosophers);
	philosophers->last_meal_time = get_time_in_ms();
	put_with_lock("%ld %ld is eating\n", philosophers);
	wait_death(philosophers, (philosophers->time_to_eat) * 1000);
	check_meals(philosophers);
	pthread_mutex_lock(philosophers->put_lock);
	if (*philosophers->filled_philosophers
		>= philosophers->number_of_philo && *philosophers->simulation_status)
	{
		printf("All philosophers have eaten at least %ld times\n",
			philosophers->number_of_meals);
		*philosophers->simulation_status = false;
	}
	pthread_mutex_unlock(philosophers->put_lock);
	pthread_mutex_lock(philosophers->r_fork);
	*philosophers->r_fork_available = true;
	pthread_mutex_unlock(philosophers->r_fork);
	pthread_mutex_lock(philosophers->l_fork);
	*philosophers->l_fork_available = true;
	pthread_mutex_unlock(philosophers->l_fork);
}

void	p_eat(t_philo *philosophers)
{
	pthread_mutex_lock(philosophers->put_lock);
	while (*philosophers->simulation_status)
	{
		pthread_mutex_unlock(philosophers->put_lock);
		pthread_mutex_lock(philosophers->l_fork);
		if (*philosophers->l_fork_available)
		{
			*philosophers->l_fork_available = false;
			pthread_mutex_unlock(philosophers->l_fork);
			pthread_mutex_lock(philosophers->r_fork);
			if (*philosophers->r_fork_available)
				return (eat_and_check(philosophers));
			pthread_mutex_unlock(philosophers->r_fork);
			pthread_mutex_lock(philosophers->l_fork);
			*philosophers->l_fork_available = true;
		}
		pthread_mutex_unlock(philosophers->l_fork);
		wait_death(philosophers, MAX_WAIT);
		pthread_mutex_lock(philosophers->put_lock);
	}
	pthread_mutex_unlock(philosophers->put_lock);
}
