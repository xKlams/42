/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:05:02 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/11 17:08:17 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philosophers.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/*
** Standard atoi (man atoi)
*/
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		i *= 10;
		i += *nptr - '0';
		nptr++;
	}
	return (sign * i);
}

/*
** Algebric modulo operator
*/
int	ft_modulo(int nbr, int modulo)
{
	if (nbr >= 0)
		return (nbr % modulo);
	else
		return ((nbr + modulo) % modulo);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*output;
	size_t	i;

	i = 0;
	output = (void *)malloc(nmeb * size);
	if (!output)
		return (NULL);
	while (i != size * nmeb)
	{
		((char *)output)[i] = 0;
		i++;
	}
	return (output);
}

void	*ft_memset(void *a, int c, size_t lenght)
{
	char	*p;

	p = (char *)a;
	while (lenght--)
		*(p + lenght) = c;
	return (a);
}

/*
** Sets up fork mutexes for philo variable
*/
void	init_fork(t_philo **philo, int number_of_philo)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*put_death;
	int		index;
	bool		*forks_avaliable;

	index = -1;
	forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * number_of_philo);
	forks_avaliable = (bool *)ft_calloc(
			sizeof(bool),  number_of_philo);
	ft_memset(forks_avaliable, 1, number_of_philo * sizeof(bool));
	while (++index < number_of_philo)
		pthread_mutex_init(forks + index, NULL);
	put_death = (pthread_mutex_t *) ft_calloc(sizeof(pthread_mutex_t), 1);
	pthread_mutex_init(put_death, NULL);
	index = -1;
	while (++index < number_of_philo)
	{
		philo[index]->put_lock = put_death;
		philo[index]->l_fork_available = forks_avaliable + ft_modulo(index - 1, number_of_philo);
		philo[index]->r_fork_available = forks_avaliable + ft_modulo(index, number_of_philo);
		philo[index]->r_fork = forks + ft_modulo(index - 1, number_of_philo);
		philo[index]->l_fork = forks + ft_modulo(index, number_of_philo);
	}
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
		return (EXIT_FAILURE);
	while (++index < argc)
		if (ft_atoi(argv[index]) < 1)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
** Initializes t_philo variable, doesn't sett the process
** @returns pointer to t_philo var created
*/
t_philo	**init_philo(int argc, char **argv)
{
	t_philo		**output;
	int		number_of_philo;
	int		index;
	size_t		starting_time;
	size_t		*filled_philosophers;
	bool		*simulation_status;

	index = -1;

	simulation_status = (bool *) malloc(sizeof(bool));
	*simulation_status = true;
	filled_philosophers = (size_t *) malloc(sizeof(size_t));
	*filled_philosophers = 0;
	starting_time = get_time_in_ms();
	if (arg_check(argc, argv))
		exit(EXIT_FAILURE);
	number_of_philo = ft_atoi(argv[1]);
	output = (t_philo **)ft_calloc(sizeof(t_philo *), (number_of_philo + 1));
	output[number_of_philo] = NULL;
	while (++index < number_of_philo)
	{
		output[index] = (t_philo *)malloc(sizeof(t_philo));
		output[index]->id = index + 1;
		output[index]->number_of_philo = number_of_philo;
		output[index]->filled_philosophers = filled_philosophers;
		output[index]->time_to_die = ft_atoi(argv[2]);
		output[index]->time_to_eat = ft_atoi(argv[3]);
		output[index]->time_to_sleep = ft_atoi(argv[4]);
		output[index]->meals_eaten = 0;
		output[index]->starting_time = starting_time;
		output[index]->number_of_meals = 0;
		output[index]->simulation_status = simulation_status;
		output[index]->last_meal_time = starting_time;
		output[index]->is_dead = 0;
		output[index]->death_lock = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((output[index])->death_lock, NULL);
		if (argc == 6)
			output[index]->number_of_meals = ft_atoi(argv[5]);
	}
	init_fork(output, number_of_philo);
	return (output);
}
