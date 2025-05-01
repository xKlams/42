/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:34:28 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/28 17:49:55 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Checks if all the characters in the string are digits
*/
int	are_all_digits(char **command)
{
	int	i;
	int	j;

	i = 1;
	while (command[i])
	{
		j = 0;
		while (command[i][j] == '0' || (command[i][j] >= 9
				&& command[i][j] <= 13) || command[i][j] == ' ')
			j++;
		if (command[i][j] == '+' || command[i][j] == '-')
			j++;
		while (command[i][j])
		{
			if (!(command[i][j] >= '0' && command[i][j] <= '9'))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	modulo_str_greater(char *string, char *value)
{
	int	i;

	i = 0;
	while (string[i] == '0' || (string[i] >= 9 && string[i] <= 13)
		|| string[i] == ' ')
		i++;
	if (string[i] == '-')
	{
		i++;
		if (ft_isdigit(value[0]) || value[0] == '+')
			return (false);
		value++;
	}
	else if (value[0] == '-')
		return (false);
	if (string[i] == '+')
		i++;
	if (ft_strlen(string + i) > ft_strlen(value))
		return (true);
	if (ft_strlen(string + i) < ft_strlen(value))
		return (false);
	if (ft_strncmp(string + i, value, ft_strlen(value)) > 0)
		return (true);
	return (false);
}

void	ft_exit_utils(char **command, long int last_exit,
		long int *exit_code)
{
	if (!command)
		return ;
	if (command && (command[1] != NULL
			&& command[2] != NULL))
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	else if (command && command[1] == NULL)
		*exit_code = last_exit;
	else if ((command && are_all_digits(command))
		|| modulo_str_greater(command[1], "9223372036854775807")
		|| modulo_str_greater(command[1], "-9223372036854775808")
		|| !command[1][0])
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(command[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		*exit_code = 2;
	}
	else if (command)
		*exit_code = ft_long_atoi(command[1]);
}

/*
** Exits the shell with appropriate exit_code
*/
void	ft_exit(t_parser_result *parsed_input, t_tools *tool,
		char **command)
{
	long int	exit_code;

	exit_code = 1;
	rl_clear_history();
	if (tool)
	{
		ft_exit_utils(command, tool->last_exit_code, &exit_code);
		if (tool->input)
		{
			free(tool->input);
			tool->input = NULL;
		}
		if (tool->command_start && tool->command_len)
			free_size_string_array(tool->command_start, tool->command_len);
		free_string_array(tool->envp);
		free(tool);
	}
	if (command)
	{
		free_string_array(command);
		command = NULL;
	}
	if (parsed_input)
		parser_result_free(parsed_input);
	exit(exit_code);
}
