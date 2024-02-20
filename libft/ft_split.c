/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:03:01 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/20 18:48:44 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	return (i);
}

size_t	pointer_dist(char const *from, char const *to)
{
	size_t	i;

	i = 0;
	while (from + i != to)
		i++;
	return (i);
}

void	ft_aux(char *start, char **list, char c, const char *s)
{
	while (*s == c)
		s++;
	while (*s)
	{
		start = (char *)s;
		while (*s != c && *s)
			s++;
		*list = ft_substr(start, 0, pointer_dist(start, s));
		if (!(*list))
			free(*list);
		list++;
		while (*s == c && *s)
			s++;
	}
	*list = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	char	*start;
	char	**list_start;

	if (!s)
		return (NULL);
	start = (char *)s;
	while (*(s) == c && *s)
		s++;
	if (*s == 0)
	{
		list = (char **)malloc(sizeof(char *));
		if (!list)
			return (NULL);
		*list = NULL;
		return (list);
	}
	s = start;
	list = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	list_start = list;
	ft_aux(start, list, c, s);
	return (list_start);
}
