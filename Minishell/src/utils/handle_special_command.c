/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_special_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:17:52 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/28 17:52:03 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	setup_command_redirections(t_command *command_info, int fd_save[2])
{
	fd_save[0] = dup(STDIN_FILENO);
	fd_save[1] = dup(STDOUT_FILENO);
	if (command_info->in_fd != 0)
		dup2(command_info->in_fd, STDIN_FILENO);
	if (command_info->out_fd != -42)
		dup2(command_info->out_fd, STDOUT_FILENO);
}

static int	exec_builtin(char **args, t_parser_result *parsed_input,
		t_tools *tool, t_command *command_info)
{
	if (ft_strncmp(args[0], "exit", 5) == 0)
	{
		rl_clear_history();
		ft_putstr_fd("exit\n", 2);
		free(command_info);
		ft_exit(parsed_input, tool, args);
	}
	if (ft_strncmp(args[0], "cd", 3) == 0)
	{
		tool->last_exit_code = cd(parsed_input->command, tool);
		return (1);
	}
	if (ft_strncmp(args[0], "export", 7) == 0)
	{
		tool->last_exit_code = export(parsed_input->command, &(tool->envp));
		return (1);
	}
	if (ft_strncmp(args[0], "unset", 6) == 0)
	{
		tool->last_exit_code = unset(parsed_input->command, &(tool->envp));
		return (1);
	}
	return (0);
}

static void	cleanup_after_builtin(int fd_save[2],
		t_parser_result *parsed_input, t_command *cmd_info)
{
	dup2(fd_save[0], STDIN_FILENO);
	dup2(fd_save[1], STDOUT_FILENO);
	free_string_array(parsed_input->command);
	parser_result_free(parsed_input);
	parsed_input = NULL;
	free(cmd_info);
	cmd_info = NULL;
}

int	handle_special_command(t_parser_result *parsed_input, char *input,
		t_tools *tool, t_command *command_info)
{
	int	fd_save[2];
	int	flag;

	(void) input;
	setup_command_redirections(command_info, fd_save);
	free(command_info->command_with_path);
	parsed_input->command = command_info->args;
	flag = exec_builtin(command_info->args, parsed_input, tool, command_info);
	if (flag)
	{
		free(tool->input);
		tool->input = NULL;
		free_size_string_array(tool->command_start, tool->command_len);
		tool->command_start = NULL;
		cleanup_after_builtin(fd_save, parsed_input, command_info);
		return (1);
	}
	return (0);
}
