/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:46:18 by fde-sist          #+#    #+#             */
/*   Updated: 2023/10/12 10:46:19 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = -1;
	while (str[++k])
	{
		j = 0;
		while (str[k][j++])
			i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (size == 0)
		return (NULL);
	arr = (char *)malloc((size - 1) * ft_strlen(sep) + ft_len(strs) + 1);
	while (*strs)
	{
		while (**strs)
		{
			arr[j++] = **strs;
			(*strs)++;
		}
		i = 0;
		while (sep[i] && k < size - 1)
			arr[j++] = sep[i++];
		k++;
		strs++;
	}
	arr[j] = 0;
	return (arr);
}
