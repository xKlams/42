/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:18:03 by fde-sist          #+#    #+#             */
/*   Updated: 2024/03/04 16:05:34 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_with_leftover(char leftover[])
{
	char	*out;
	char	*temp;
	int		i;

	i = 0;
	out = (char *)malloc(1);
	*out = 0;
	if (ft_strchr(leftover, '\n') != -1)
	{
		out = ft_strjoin_until(out, leftover, ft_strchr(leftover, '\n') + 1);
		temp = ft_strdup(leftover + ft_strchr(leftover, '\n') + 1);
		ft_strlcpy(leftover, temp, BUFFER_SIZE + 1);
		free(temp);
		return (out);
	}
	free(out);
	out = ft_strdup(leftover);
	while (i < BUFFER_SIZE + 1)
	{
		leftover[i] = 0;
		i++;
	}
	return (out);
}

char	*ft_aux(char leftover[], char *line, int br, int fd)
{
	char	*temp;
	int		nl_index;

	while (br)
	{
		if (ft_strchr(leftover, '\n') != -1)
		{
			nl_index = ft_strchr(leftover, '\n') + 1;
			line = ft_strjoin_until(line, leftover, nl_index);
			temp = ft_strdup(leftover + ft_strchr(leftover, '\n') + 1);
			ft_strlcpy(leftover, temp, BUFFER_SIZE + 1);
			free(temp);
			return (line);
		}
		line = ft_strjoin_until(line, leftover, BUFFER_SIZE + 1);
		br = read(fd, leftover, BUFFER_SIZE);
		leftover[br] = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	leftover[1025][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	if (*(leftover[fd]))
	{
		line = fill_with_leftover(leftover[fd]);
		if (ft_strchr(line, '\n') != -1)
			return (line);
	}
	bytes_read = read(fd, leftover[fd], BUFFER_SIZE);
	leftover[fd][bytes_read] = 0;
	if (bytes_read == -1)
		return (NULL);
	if (bytes_read == 0)
		return (line);
	if (line == NULL)
	{
		line = (char *)malloc(1);
		*line = 0;
	}
	return (ft_aux(leftover[fd], line, bytes_read, fd));
}
