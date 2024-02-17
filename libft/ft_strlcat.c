/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:33:35 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/16 16:16:34 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
		dst[i + j] = 0;
	return (i + ft_strlen(src));
}
