/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:03:43 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/27 17:40:17 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** echo builtin, -n flag is handled
*/
static int	check_n_flag(char **command, int *i)
{
	int	n_flag;
	int	j;

	n_flag = 0;
	while (command[*i])
	{
		if (command[*i][0] == '-' && command[*i][1] == 'n')
		{
			j = 2;
			while (command[*i][j] == 'n')
				j++;
			if (command[*i][j] != '\0')
				break ;
			n_flag = 1;
			(*i)++;
		}
		else
			break ;
	}
	return (n_flag);
}

int	echo(char **command)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = check_n_flag(command, &i);
	while (command[i])
	{
		ft_putstr_fd(command[i], STDOUT_FILENO);
		if (command[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', 1);
	return (EXIT_SUCCESS);
}
