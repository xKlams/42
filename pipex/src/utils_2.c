/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:56:28 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 00:35:20 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(int pipefd[2], int files[2], char **envp, char **params)
{
	char	**command;
	int		pid;

	close(pipefd[0]);
	dup2(files[0], STDIN_FILENO);
	close(files[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	command = ft_split(params[1], ' ');
	execve(command[0], command, envp);
	perror("Error");
	free_str_array(command, -1);
	free_str_array(params, 4);
	return (EXIT_FAILURE);
}

int	parent(int pipefd[2], int files[2], char **envp, char **params)
{
	char	**command;

	command = ft_split(params[2], ' ');
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(files[1], STDOUT_FILENO);
	close(files[1]);
	execve(command[0], command, envp);
	perror("Error");
	return (EXIT_SUCCESS);
}

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

/*Replaces tabs with spaces*/
void	fix_input(char **argv)
{
	int	i;

	i = -1;
	while (argv[2][++i])
		if (argv[2][i] <= 13 && argv[2][i] >= 9)
			argv[2][i] = ' ';
	i = -1;
	while (argv[3][++i])
		if (argv[3][i] <= 13 && argv[3][i] >= 9)
			argv[3][i] = ' ';
}
