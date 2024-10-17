/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:22:00 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 12:10:03 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(int pipefd[2], int files[2], char **envp, char **params)
{
	char	**command;

	if (!params[1])
	{
		free_str_array(params, 4);
		return (EXIT_FAILURE);
	}
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
	return (EXIT_FAILURE);
}

int	second_command(char **params, char **envp, int files[2])
{
	char	**command;

	if (!params[2])
	{
		free_str_array(params, 4);
		return (EXIT_FAILURE);
	}
	command = ft_split(params[2], ' ');
	files[0] = open("/tmp", __O_TMPFILE | O_RDWR);
	dup2(files[0], STDIN_FILENO);
	close(files[0]);
	dup2(files[1], STDOUT_FILENO);
	close(files[1]);
	execve(command[0], command, envp);
	perror("Error");
	free_str_array(command, -1);
	free_str_array(params, 4);
	return (EXIT_FAILURE);
}

int	ft_pipe(char **params, char **envp, int files[2])
{
	int		pipefd[2];
	int		pid;
	int		wstatus;

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
		if (!params[2])
		{
			free_str_array(params, 4);
			return (EXIT_FAILURE);
		}
		return (parent(pipefd, files, envp, params));
	}
	if (waitpid(pid, &wstatus, 0) == -1 || WIFEXITED(wstatus) == 0)
		exit(1);
	return (EXIT_FAILURE);
}
