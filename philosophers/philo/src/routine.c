/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:14:20 by fde-sist          #+#    #+#             */
/*   Updated: 2025/03/12 14:14:23 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philosophers.h"

void	p_sleep(t_philo *philosophers)
{
	put_with_lock("%ld %ld is sleeping\n", philosophers);
	wait_death(philosophers, philosophers->time_to_sleep * 1000);
}

void	p_think(t_philo *philosophers)
{
	put_with_lock("%ld %ld is thinking\n", philosophers);
}

void	do_action(t_philo *philosopher, int action)
{
	if (action == 0)
		p_eat(philosopher);
	if (action == 1)
		p_sleep(philosopher);
	if (action == 2)
		p_think(philosopher);
}

void	philo_routine(t_philo *philosophers)
{
	int	action;

	action = 0;
	while (1)
	{
		pthread_mutex_lock(philosophers->put_lock);
		if (!*philosophers->simulation_status)
			break ;
		pthread_mutex_unlock(philosophers->put_lock);
		do_action(philosophers, action);
		wait_death(philosophers, MAX_WAIT);
		action = (action + 1) % 3;
	}
	pthread_mutex_unlock(philosophers->put_lock);
	return ;
}
