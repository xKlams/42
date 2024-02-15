/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:33:35 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/15 13:48:03 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	dst_len;

	i = 0;
	while (dst[i++]);
	dst_len = --i;
	
	while (src[i - dst_len] && i - dst_len < (int)(size - 1))
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	return (i);
}