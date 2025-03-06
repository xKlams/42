#include "../libs/philosophers.h"

void	eat_and_check(t_philo *philosophers)
{
	*philosophers->r_fork_available = false;
	pthread_mutex_unlock(philosophers->r_fork);
	put_with_lock("%ld %ld has taken a fork\n", philosophers);
	put_with_lock("%ld %ld has taken a fork\n", philosophers);
	philosophers->last_meal_time = get_time_in_ms();
	put_with_lock("%ld %ld is eating\n", philosophers);
	usleep(philosophers->time_to_eat * 1000);
	philosophers->meals_eaten++;
	if (philosophers->number_of_meals
		&& philosophers->meals_eaten
		>= philosophers->number_of_meals)
	{
		if (!philosophers->is_full)
			(*philosophers->filled_philosophers)++;
		philosophers->is_full = true;
	}
	if (*philosophers->filled_philosophers
		>= philosophers->number_of_philo)
		*philosophers->simulation_status = false;
	pthread_mutex_lock(philosophers->r_fork);
	pthread_mutex_lock(philosophers->l_fork);
	*philosophers->r_fork_available = true;
	*philosophers->l_fork_available = true;
	pthread_mutex_unlock(philosophers->r_fork);
	pthread_mutex_unlock(philosophers->l_fork);
}

void	p_eat(t_philo *philosophers)
{
	while (!is_dead(philosophers) && *philosophers->simulation_status)
	{
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
	}
}
