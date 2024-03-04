/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:41:45 by fde-sist          #+#    #+#             */
/*   Updated: 2024/03/04 14:40:21 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


char	*get_next_line(int fd);
char	*fill_with_leftover(char leftover[BUFFER_SIZE + 1]);
char	*ft_strjoin_until(char *s1, char *s2, int until);
int	    ft_strchr(const char *s, int c);
char	*ft_aux(char leftover[BUFFER_SIZE + 1], char *line, int bytes_read, int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char	*dst, const char *src, size_t size);

#endif