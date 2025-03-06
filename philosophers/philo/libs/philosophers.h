/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:30:22 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/25 16:46:05 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <time.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <curses.h>

# define MAX_WAIT 3

typedef struct s_philo
{
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*death_lock;
	pthread_mutex_t		*put_lock;
	pthread_t		process;
	size_t			*filled_philosophers;
	size_t			number_of_philo;
	size_t			starting_time;
	size_t			id;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_of_meals;
	size_t			meals_eaten;
	size_t			last_meal_time;
	size_t			is_dead;
	bool			is_full;
	bool			*simulation_status;
	bool			*l_fork_available;
	bool			*r_fork_available;
}	t_philo;

int		ft_atoi(const char *nptr);
int		ft_modulo(int nbr, int modulo);
void	init_fork(t_philo **philo, int number_of_philo);
int		arg_check(int argc, char **argv);
t_philo	**init_philo(int argc, char **argv);
time_t	get_time_in_ms(void);
bool	is_dead(t_philo *philosopher);
time_t	get_time_in_ms(void);
size_t	ft_min(size_t a, size_t b);
void	wait_death(t_philo *philosophers, size_t max_wait);
void	put_with_lock(char *buffer, t_philo *philo);
void	p_eat(t_philo *philosophers);
void	philo_routine(t_philo *philosophers);


#endif
