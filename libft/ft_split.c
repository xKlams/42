/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:17:39 by fde-sist          #+#    #+#             */
/*   Updated: 2024/02/19 16:33:45 by fde-sist         ###   ########.fr       */
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
		i++;
		// printf("new element added %s at index i = %d\n", list[i-1], i -1);
		s += until_new_char(s,c);
		while (*s == c && *s)
			s++;
	}
	list[i] = NULL;
	// printf("i = %d\n", i);
	// 	printf("new element added %s at index i = %d\n", list[i], i);
	// 	printf("%s\n", list[12]);
	return (list);
}
int main()
{
	char **test = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	for(int i = 0 ; i < count_words("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ' ) + 1; i++)
		{
			printf("%s\n", test[i] );
	}// printf("%s\n", test[2]);

}
