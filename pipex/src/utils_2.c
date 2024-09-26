/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:56:28 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/26 00:44:50 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(int pipefd[2], int files[2], char **envp, char **params)
{
	char	**command;

	close(pipefd[0]);
	dup2(files[0], STDIN_FILENO);
	close(files[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	command = ft_split(params[1], ' ');
	execve(command[0], command, envp);
	perror("Error");
	return (EXIT_FAILURE);
}

int	parent(int pipefd[2], int files[2], char **envp, char **params)
{
	char	**command;
	int		status;
	int		child_status;

	status = fork();
	command = ft_split(params[2], ' ');
	if (status == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (status == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		dup2(files[1], STDOUT_FILENO);
		close(files[1]);
		execve(command[0], command, envp);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		free_str_array(command);
		free_str_array(params);
	}
	return (EXIT_SUCCESS);
}

void	free_str_array(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
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
