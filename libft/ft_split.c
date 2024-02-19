/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:03:01 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/19 18:54:58 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	change;

	i = 0;
	change = 0;
	while (*s)
	{
		while (*s == c && *s)
		{
			s++;
			change = 1;
		}
		if (!*s)
			return (i + 1);
		if (change)
			i++;
		change = 0;
		s++;
	}
	return (i + 1);
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
	while (*s == c)
		s++;
	ft_aux(start, list, c, s);
	return (list_start);
}
