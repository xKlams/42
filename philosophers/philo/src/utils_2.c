/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:29:59 by fde-sist          #+#    #+#             */
/*   Updated: 2025/03/12 14:30:08 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philosophers.h"
#include <pthread.h>

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

void	set_forks(t_philo **philo, bool **forks_avaliable,
		int number_of_philo, pthread_mutex_t **forks)
{
	int				index;
	pthread_mutex_t	*put_lock;
	pthread_mutex_t	*increment_meals;

	put_lock = (pthread_mutex_t *) ft_calloc(sizeof(pthread_mutex_t), 1);
	increment_meals = (pthread_mutex_t *) ft_calloc(sizeof(pthread_mutex_t), 1);
	pthread_mutex_init(put_lock, NULL);
	pthread_mutex_init(increment_meals, NULL);
	index = -1;
	while (++index < number_of_philo)
	{
		philo[index]->put_lock = put_lock;
		philo[index]->increment_meals = increment_meals;
		philo[index]->r_fork_available = (forks_avaliable[ft_modulo(index - 1,
					number_of_philo)]);
		philo[index]->l_fork_available = (forks_avaliable[ft_modulo(index,
					number_of_philo)]);
		philo[index]->r_fork = forks[ft_modulo(index - 1, number_of_philo)];
		philo[index]->l_fork = forks[ft_modulo(index, number_of_philo)];
	}
}
