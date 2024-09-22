/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:56:28 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/23 00:09:39 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int pipefd[2], int files[2], char **envp, char **params)
{
	char	**command;

	close(pipefd[0]);
	dup2(files[0], STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	command = ft_split(params[1], ' ');
	execve(command[0], command, envp);
	perror("Error");
	close(pipefd[1]);
}

void	father(int pipefd[2], int files[2], char **envp, char **params)
{
	char	**command;

	wait(NULL);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(files[1], STDOUT_FILENO);
	command = ft_split(params[2], ' ');
	execve(command[0], command, envp);
	perror("Error");
	close(pipefd[0]);
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
