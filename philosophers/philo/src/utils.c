/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:14:33 by fde-sist          #+#    #+#             */
/*   Updated: 2025/03/12 14:14:33 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philosophers.h"

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
