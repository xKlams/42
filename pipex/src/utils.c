/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:56:28 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 01:26:44 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_str_array(char **str_array, int len)
{
	int	i;

	i = 0;
	if (len == -1)
	{
		while (str_array[i])
		{
			free(str_array[i]);
			i++;
		}
		free(str_array);
		str_array = NULL;
		return ;
	}
	while (i < len)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
	str_array = NULL;
}

int	ft_max(int a, int b)
{
	return (a * (a > b) + b * (b >= a));
}

void	write_error(char *error_message, char *file_name)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error_message, 2);
}

void	error_handler(char *first, char *second, int flag, char **argv)
{
	if (!first && flag != -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (!second)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}
