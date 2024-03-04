/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:41:39 by fde-sist          #+#    #+#             */
/*   Updated: 2024/03/04 15:14:47 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_until(char *s1, char *s2, int until)
{
	char	*joined;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *) malloc((len) * sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	ft_strlcpy(joined + ft_strlen(s1), s2, until + 1);
	free(s1);
	return (joined);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (-1);
	}
	while (s[i])
	{
		if (s[i] == (char) c)
			return (i);
		i++;
	}
	if (s[i] == (char) c)
		return (i);
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new_string;
	char	*start;

	new_string = (char *)malloc(ft_strlen(s) + 1);
	if (!new_string)
		return (NULL);
	start = new_string;
	while (*s)
	{
		*new_string = *s;
		new_string++;
		s++;
	}
	*new_string = *s;
	return (start);
}

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	copied_chars;

	if (!size)
		return (ft_strlen(src));
	copied_chars = 0;
	while (copied_chars + 1 < size && src[copied_chars])
	{
		dst[copied_chars] = src[copied_chars];
		copied_chars++;
	}
	if (size != 0)
		dst[copied_chars] = 0;
	return (ft_strlen(src));
}
