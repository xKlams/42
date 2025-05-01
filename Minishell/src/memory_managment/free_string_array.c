/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:41:51 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 15:47:28 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Frees a string array
 * 
 */
void	free_string_array(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	print_string_array(char **str)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putstr_fd("\"", 2);
		ft_putstr_fd(*str, 2);
		ft_putstr_fd("\" ", 2);
		str++;
	}
	ft_putstr_fd("\n", 2);
}

void	free_size_string_array(char **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
