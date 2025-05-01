/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:42:27 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/26 12:20:49 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Outputs debug on screen*/
int	command_not_found(char **command, int flag)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command[0], 2);
	if (flag == 1)
	{
		ft_putstr_fd(": Is a directory\n", 2);
		return (126);
	}
	else if (flag == 2)
	{
		ft_putstr_fd(": Permission denied\n", 2);
		return (126);
	}
	if (command[0] && (command[0][0] == '/' || command[0][0] == '.'))
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
	return (127);
}

/*
 ** Returns bash-like if command is invalid 0 otherwise
*/
int	invalid_command(char **command, char *command_with_path)
{
	int	output;

	output = 0;
	if (!command[0])
		return (-42);
	if (is_builtin(command[0]))
		return (0);
	if (command_with_path == NULL || access(command_with_path, F_OK | X_OK))
	{
		if (command_with_path && access(command_with_path, X_OK)
			&& !access(command_with_path, F_OK))
			output = command_not_found(command, 2);
		else
			output = command_not_found(command, 0);
		return (output);
	}
	if (is_directory(command[0]) || is_directory(command_with_path))
	{
		output = command_not_found(command, 1);
		return (output);
	}
	return (output);
}

/*Outputs debug on screen*/
void	ft_error(char *error_type, char **command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error_type, 2);
	ft_putstr_fd(" error\n", 2);
	free_string_array(command);
	exit(EXIT_FAILURE);
}

/*
** @return if command is not executed, returns bash error 
** code, otherwise returns 0
*/
int	command_error_handler(t_command *command_info, int pipefd[2])
{
	int	exit_value;

	exit_value = invalid_command(command_info->args,
			command_info->command_with_path);
	if (exit_value)
	{
		if (pipefd)
		{
			close(pipefd[0]);
			close(pipefd[1]);
		}
		return (exit_value);
	}
	if (command_info->in_fd == -1 || command_info->out_fd == -1)
	{
		if (pipefd)
		{
			close(pipefd[0]);
			close(pipefd[1]);
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
