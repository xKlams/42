/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:17:39 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/19 14:43:56 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
		if(!*s)
			return(i + 1);
		if (change)
			i++;
		change = 0;
		s++;
	}
	return (i + 1);
}

size_t	until_new_char(const char *s1, char c)
{
	size_t	i;

	i = 1;
	while (*s1 != c)
	{
		if (!*s1)
			return (i);
		i++;
		s1++;
	}
	return (i);
}
// #include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char		**list;
	int			i;

	while(*s == c && *s)
		s++;
	i = 0;
	list = (char **)malloc((count_words(s, c) + 1)*sizeof(char *));
	// printf("words = %d\n", count_words(s, c));
	if(!list)
	return (NULL);
	while (*s == c)
		s++;
	if (!(*s))
	{
		*list = NULL;
		return (list);
	}
	while (*s)
	{
		list[i] = ft_substr(s, 0, until_new_char(s, c) - 1);
		if(!list)
			return (NULL);
		i++;
		s += until_new_char(s,c);
		while (*s == c && *s)
			s++;
	}
	list[i] = NULL;
	return (list);
}

// int main()
// {
// 	for(int i = 0 ; i < 1; i++)
// 	printf("%s\n", ft_split("hello!", ' ')[i]);

// }