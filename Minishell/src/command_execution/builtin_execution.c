/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:16:30 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/28 17:50:36 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @return if command is a builtin
*/
bool	is_builtin(char *command)
{
	if (ft_strncmp(command, "exit", 5) == 0)
		return (true);
	if (ft_strncmp(command, "env", 4) == 0)
		return (true);
	if (ft_strncmp(command, "pwd", 4) == 0)
		return (true);
	if (ft_strncmp(command, "cd", 3) == 0)
		return (true);
	if (ft_strncmp(command, "echo", 5) == 0)
		return (true);
	if (ft_strncmp(command, "export", 7) == 0)
		return (true);
	if (ft_strncmp(command, "unset", 6) == 0)
		return (true);
	return (false);
}

/*
** Executes the builtin command
*/
void	execute_builtin(t_parser_result *parsed_input, t_tools *tool,
		char **command, t_command *command_info)
{
	int	exit_code;

	exit_code = -1;
	if (ft_strncmp(command[0], "exit", 5) == 0)
	{
		free(command_info);
		ft_exit(parsed_input, tool, command);
	}
	else if (ft_strncmp(command[0], "env", 4) == 0)
		exit_code = env(tool->envp, command);
	else if (ft_strncmp(command[0], "pwd", 4) == 0)
		exit_code = pwd();
	else if (ft_strncmp(command[0], "cd", 3) == 0)
		exit_code = cd(command, tool);
	else if (ft_strncmp(command[0], "echo", 5) == 0)
		exit_code = echo(command);
	else if (ft_strncmp(command[0], "export", 7) == 0)
		exit_code = export(command, &(tool->envp));
	else if (ft_strncmp(command[0], "unset", 6) == 0)
	{
		exit_code = 0;
		unset(command, &(tool->envp));
	}
	if (exit_code != -1)
		exit_clean_up(tool, exit_code, parsed_input, command_info);
}
