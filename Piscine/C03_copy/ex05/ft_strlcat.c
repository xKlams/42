/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:08:40 by fde-sist          #+#    #+#             */
/*   Updated: 2023/09/27 19:16:39 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;

	dest_len = len(dest);
	i = 0;
	while (src[i] && dest_len + i < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (len(dest));
}
