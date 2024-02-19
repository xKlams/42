/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:37:22 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/19 12:22:56 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	char	*joined;
	int		len_s2;
	int		len_s1;

	index = 0;
	if (!s1 && !s2)
		return (NULL);
	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	joined = (char *) malloc(len_s1 + len_s2 + 1);
	if (!joined)
		return (NULL);
	while (s1[index])
	{
		joined[index] = s1[index];
		index++;
	}
	while (s2[index - len_s1])
	{
		joined[index] = s2[index - len_s1];
		index++;
	}
	joined[index] = 0;
	return (joined);
}
