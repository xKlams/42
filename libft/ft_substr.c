/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:13:56 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/19 12:22:03 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subsring;
	unsigned int	index;
	size_t			s_len;

	index = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		subsring = malloc(1);
		subsring[0] = 0;
		return (subsring);
	}
	if (s_len - start < len)
		subsring = (char *)malloc(s_len - start + 1);
	else
		subsring = (char *)malloc(len + 1);
	if (!subsring)
		return (NULL);
	while (index < (unsigned int) len && index + start <= s_len)
	{
		subsring[index] = s[index + start];
		index++;
	}
	subsring[index] = '\0';
	return (subsring);
}
