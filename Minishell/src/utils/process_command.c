/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:24:58 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/28 17:52:25 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parser_result	*parse_and_check_input(char *input, t_tools *tool)
{
	t_parser_result	*parsed_input;

	parsed_input = parse(input, tool, &tool->last_exit_code);
	if (parsed_input == NULL)
	{
		if (tool->last_exit_code == -42)
			tool->last_exit_code = 2;
		free(input);
		return (NULL);
	}
	tool->input = input;
	tool->command_start = parsed_input->command;
	tool->command_len = string_array_size(parsed_input->command);
	if (!parsed_input->command || !*(parsed_input->command))
	{
		parser_result_free(parsed_input);
		free(input);
		return (NULL);
	}
	return (parsed_input);
}

static int	validate_command(t_parser_result *parsed_input, t_tools *tool,
		char *input)
{
	(void) input;
	if (check_valid_command(parsed_input) == EXIT_FAILURE)
	{
		tool->last_exit_code = 2;
		free(tool->input);
		tool->input = NULL;
		free_size_string_array(tool->command_start, tool->command_len);
		parsed_input->command = NULL;
		tool->command_start = NULL;
		free(parsed_input->quotes);
		free(parsed_input);
		return (0);
	}
	return (1);
}

static int	handle_command_type(t_parser_result *parsed_input, t_tools *tool,
		char *input)
{
	t_command	*command_info;

	if (!are_pipes_in_command(parsed_input->command)
		&& special_command_check(parsed_input->command))
	{
		command_info = set_command_info(parsed_input, tool);
		if (command_info->in_fd == -1 || command_info->out_fd == -1)
		{
			free(tool->input);
			tool->input = NULL;
			free_string_array(command_info->args);
			free(command_info);
			free_size_string_array(tool->command_start, tool->command_len);
			return (1);
		}
		if (handle_special_command(parsed_input, input, tool, command_info))
			return (1);
		free_string_array(command_info->args);
		free(command_info);
	}
	return (0);
}

void	process_command(char **input, t_tools *tool)
{
	t_parser_result	*parsed_input;

	parsed_input = parse_and_check_input(*input, tool);
	if (parsed_input == NULL)
		return ;
	if (!validate_command(parsed_input, tool, *input))
		return ;
	if (handle_command_type(parsed_input, tool, *input))
		return ;
	tool->last_exit_code = execute_command(tool, parsed_input);
	parser_result_free(parsed_input);
	free_size_string_array(tool->command_start, tool->command_len);
	tool->command_start = NULL;
	free(tool->input);
	tool->input = NULL;
}
