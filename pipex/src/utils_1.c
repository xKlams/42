/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:38:15 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/27 15:41:24 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Returns a list of the paths included in the PATH enviroment variable*/
char	**find_path(char **envp)
{
	int		index;
	char	**output;
	char	*aux;

	index = 0;
	while (envp[index] != NULL)
	{
		if (!ft_strncmp(envp[index], "PATH=", 5))
			break ;
		index++;
	}
	if (envp[index] == NULL)
		return (NULL);
	envp[index] += 5;
	output = ft_split(envp[index], ':');
	index = 0;
	while (output[index])
	{
		aux = ft_strjoin(output[index], "/");
		free(output[index]);
		output[index++] = aux;
	}
	return (output);
}

void	write_error(char *error_message, char *file_name, int *flag)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error_message, 2);
	*flag = 0;
}

int	set_fd(int files[2], char **params, int flag)
{
	if (access(params[0], F_OK))
		write_error("No such file or directory", params[0], &flag);
	else if (access(params[0], R_OK))
		write_error("Permission denied", params[0], &flag);
	if (!access(params[3], F_OK) && access(params[3], W_OK))
		write_error("Permission denied", params[3], &flag);
	else
	{
		if (!access(params[3], F_OK) && !access(params[3], W_OK))
			unlink(params[3]);
		open(params[3], O_CREAT, 00644);
	}
	if (flag ==0 )
	{
		free_str_array(params, 4);
		return (EXIT_FAILURE);
	}
	files[0] = open(params[0], O_RDONLY);
	files[1] = open(params[3], O_WRONLY);
	return (EXIT_SUCCESS);
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
		return (parent(pipefd, files, envp, params));
	}
	return (EXIT_FAILURE);
}
int	ft_pipe(char **params, char **envp, int flag)
{
	int		files[2];
	
	if (set_fd(files, params, flag))
		return (EXIT_FAILURE);
	if (params[1] == NULL)
		standard_behaviour(params, envp, files)
	else
	{
		//TODO copiare codice di parent con file temp
	}
}

/*Returns an array of strings:
output[0] = input_file
output[1] = first_comand with flags
output[2] = second_command with flags
output[3] = output_file*/
char	**set_params(char **argv, char **paths)
{
	char	**output;
	char	*path_to_command;
	int		i;

	output = (char **)malloc(sizeof(char *) * 5);
	output[0] = ft_strdup(argv[1]);
	output[1] = NULL;
	output[2] = NULL;
	output[3] = ft_strdup(argv[4]);
	output[4] = NULL;
	i = -1;
	while (paths[++i])
	{
		path_to_command = ft_strjoin_fw(paths[i], argv[2]);
		if (!access(path_to_command, F_OK | X_OK) && !output[1])
			output[1] = ft_strjoin(paths[i], argv[2]);
		free(path_to_command);
		path_to_command = ft_strjoin_fw(paths[i], argv[3]);
		if (!access(path_to_command, F_OK | X_OK) && !output[2])
			output[2] = ft_strjoin(paths[i], argv[3]);
		free(path_to_command);
		free(paths[i]);
	}
	free(paths);
	error_handler(argv[2], argv[3]);
	return (output);
}

void	error_handler(char *first_command, char *second_command)
{
	if (!first_command)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(first_command, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (!second_command)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(second_command, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}
