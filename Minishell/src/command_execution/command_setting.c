/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:25:04 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 17:57:37 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Returns the found path+command, NULL if command is not found
*/
char	*set_command(char **command, char **paths, char **envp)
{
	char	*path_to_command;
	int		i;
	char	*output;

	output = NULL;
	if (!command || !*command)
		return (NULL);
	if (is_builtin(command[0]))
		return (NULL);
	if (!paths)
		return (NULL);
	if (is_path(*command))
		return (path_command(command, envp));
	if (is_command(command[0], paths))
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		path_to_command = ft_strjoin(paths[i], *command);
		if (!access(path_to_command, F_OK | X_OK) && !output)
			output = ft_strjoin(paths[i], *command);
		free(path_to_command);
	}
	return (output);
}

/*
** Sets up command array and returns command with whole path
*/
char	*path_command(char **command, char **envp)
{
	char	*aux;
	char	*output;

	if ((*command)[0] == '~')
	{
		output = ft_strjoin(get_value_envp("HOME=", envp), (*command));
		output[0] = '/';
		output[ft_strlen(output) - ft_strlen(*command)] = '/';
		printf("output = %s\n", output);
	}
	else if ((*command)[0] == '.')
	{
		aux = ft_strjoin(get_value_envp("PWD=", envp), "/");
		output = ft_strjoin(aux, (*command));
		free(aux);
	}
	else
		absolute_path_case(command, &output);
	return (output);
}

/*Sets up command array in case of absolute path is passed*/
void	absolute_path_case(char **command, char **output)
{
	*output = ft_strdup((*command));
	if (!is_directory(*output) && !access(*output, F_OK | X_OK))
	{
		free((*command));
		(*command) = ft_strdup(ft_strrchr(*output, '/') + 1);
	}
}
