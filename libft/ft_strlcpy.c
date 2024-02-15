/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:37:51 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/15 13:33:06 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	int	copied_chars;

	copied_chars = 0;
	while (copied_chars < (int)(size - 1) && src[copied_chars])
	{
		dst[copied_chars] = src[copied_chars];
		copied_chars++;
	}
	if (size != 0)
		dst[copied_chars] = 0;
	return (ft_strlen(src));
}
