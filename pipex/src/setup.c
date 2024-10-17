/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:38:15 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 01:29:55 by fde-sist         ###   ########.fr       */
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

int	set_fd(int files[2], char **params)
{
	if (access(params[0], F_OK))
		write_error("No such file or directory", params[0]);
	else if (access(params[0], R_OK))
		write_error("Permission denied", params[0]);
	if (!access(params[3], F_OK) && access(params[3], W_OK))
	{
		write_error("Permission denied", params[3]);
		free_str_array(params, 4);
		return (EXIT_FAILURE);
	}
	files[0] = open(params[0], O_RDONLY);
	files[1] = open(params[3], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (EXIT_SUCCESS);
}

/*Returns an array of strings:
output[0] = input_file
output[1] = first_comand with flags
output[2] = second_command with flags
output[3] = output_file*/
void	set_params(char **argv, char **paths, char **output)
{
	char	*path_to_command;
	int		i;

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
}
