#include "../libs/philosophers.h"

void	p_sleep(t_philo *philosophers)
{
	put_with_lock("%ld %ld is sleeping\n", philosophers);
	usleep(philosophers->time_to_sleep * 1000);
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
		if (is_dead(philosophers) || !*philosophers->simulation_status)
			break ;
		do_action(philosophers, action);
		wait_death(philosophers, 10);
		action = (action + 1) % 3;
	}
	return ;
}
