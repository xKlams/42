/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:13:56 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/20 21:42:08 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_subs_aux(char *s, size_t *i, char const *ss, unsigned int start)
{
	s[*i] = ss[*i + start];
	(*i)++;
}

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
		if (!substring)
			return (NULL);
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
		ft_subs_aux(substring, &index, s, start);
	substring[index] = '\0';
	return (substring);
}
