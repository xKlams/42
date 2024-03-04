/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:18:03 by fde-sist          #+#    #+#             */
/*   Updated: 2024/03/04 15:04:35 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*fill_with_leftover(char leftover[BUFFER_SIZE + 1])
{
	char	*out;
	char	*temp;
	int		i;

	i = 0;
	out = (char *)malloc(1);
	*out = 0;
	if(ft_strchr(leftover, '\n') != -1)
	{
		out = ft_strjoin_until(out, leftover, ft_strchr(leftover, '\n') + 1);
		temp = ft_strdup(leftover + ft_strchr(leftover, '\n') + 1);
		ft_strlcpy(leftover, temp, BUFFER_SIZE + 1);
		free(temp);
		return(out);
	}
	free(out);
	out = ft_strdup(leftover);
	while (i < BUFFER_SIZE + 1)
	{
		leftover[i] = 0;
		i++;
	}
	return(out);
}
char	*ft_aux(char leftover[BUFFER_SIZE + 1], char *line, int bytes_read, int fd)
{
	char *temp;

	while(bytes_read)
	{
		if (ft_strchr(leftover, '\n') != -1)
		{
			line = ft_strjoin_until(line, leftover, ft_strchr(leftover, '\n') + 1);
			temp = ft_strdup(leftover + ft_strchr(leftover, '\n') + 1);
			ft_strlcpy(leftover, temp, BUFFER_SIZE + 1);
			free(temp);
			return (line);
		}
		line = ft_strjoin_until(line, leftover, BUFFER_SIZE + 1);
		bytes_read = read(fd, leftover, BUFFER_SIZE);
		leftover[bytes_read] = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char        *line;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
    line = NULL;
	if (*leftover)
	{
		line = 	fill_with_leftover(leftover);
		if (ft_strchr(line, '\n') != -1)
			return(line);
	}
	bytes_read = read(fd, leftover, BUFFER_SIZE);
	leftover[bytes_read] = 0;
	if (bytes_read == -1)
		return(NULL);
	if (bytes_read == 0)
		return (line);
    if(line == NULL)
    {
        line = (char *)malloc(1);
        *line = 0;
    }
	return(ft_aux(leftover, line, bytes_read, fd));
}
