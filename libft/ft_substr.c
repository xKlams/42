/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist@student.42roma.it <fde-sist>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:13:56 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/23 12:37:32 by fde-sist@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		index;

	index = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substring = (char *)malloc(sizeof(char));
		*substring = '\0';
		return (substring);
	}
	if (ft_strlen(s) - start <= len)
		substring = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring || !s)
		return (NULL);
	while (index < len && index + start < ft_strlen(s) && s[index + start])
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[index] = '\0';
	return (substring);
}
