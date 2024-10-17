/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:22:00 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 01:29:40 by fde-sist         ###   ########.fr       */
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

int	ft_pipe(char **params, char **envp, int files[2])
{
	if (params[1] != NULL && files[0] != -1)
		return (standard_behaviour(params, envp, files));
	else
		return (second_command(params, envp, files));
}

int	second_command(char **params, char **envp, int files[2])
{
	char	**command;

	command = ft_split(params[2], ' ');
	files[0] = open("", __O_TMPFILE | O_RDWR);
	dup2(files[0], STDIN_FILENO);
	close(files[0]);
	dup2(files[1], STDOUT_FILENO);
	close(files[1]);
	execve(command[0], command, envp);
	perror("Error");
	return (EXIT_FAILURE);
}

int	standard_behaviour(char **params, char **envp, int files[2])
{
	int		pipefd[2];
	int		pid;

	pipe(pipefd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (!pid)
		child(pipefd, files, envp, params);
	else
	{
		wait(NULL);
		if (!params[2])
		{
			free_str_array(params, 4);
			return (EXIT_FAILURE);
		}
		return (parent(pipefd, files, envp, params));
	}
	return (EXIT_FAILURE);
}
