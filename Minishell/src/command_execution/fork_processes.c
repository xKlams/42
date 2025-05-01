/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:12:35 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 17:59:27 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Executes the command and sets up the pipes
*/
void	child_process(t_tools *tools, t_parser_result *parsed_input,
		int pipefd[2])
{
	t_command	*command_info;
	int			error_exit;

	error_exit = 0;
	command_info = set_command_info(parsed_input, tools);
	error_exit = command_error_handler(command_info, pipefd);
	if (error_exit == -42)
		exit_clean_up(tools, 0, parsed_input, command_info);
	if (error_exit)
		exit_clean_up(tools, error_exit, parsed_input, command_info);
	if (command_info->in_fd != 0)
		dup2(command_info->in_fd, STDIN_FILENO);
	if (command_info->out_fd != -42)
		dup2(command_info->out_fd, STDOUT_FILENO);
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	execute_builtin(parsed_input, tools, command_info->args, command_info);
	signal(SIGQUIT, SIG_DFL);
	execve(command_info->command_with_path, command_info->args, tools->envp);
	ft_putstr_fd("minishell: execve error\n", 2);
	exit_clean_up(tools, 127, parsed_input, command_info);
}

/*
** Checks if child process exited and handles SIGINT SIGQUIT
*/
int	parent_process(int pid, int pipefd[2], t_parser_result *parsed_input)
{
	int			status;

	signal(SIGINT, SIG_IGN);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	status = 0;
	if (*(parsed_input->command + next_command_index(parsed_input)) == NULL)
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			if (WTERMSIG(status) == SIGINT)
				write(2, "\n", 1);
			else if (WTERMSIG(status) == SIGQUIT)
				write(2, "Quit (core dumped)\n", 20);
		}
		wait(NULL);
	}
	else
		waitpid(pid, &status, WNOHANG);
	signal(SIGINT, signal_handler);
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (WEXITSTATUS(status));
}

/*
** Frees all malloced memory and exits with exit_code
*/
void	exit_clean_up(t_tools *tools, int exit_code,
		t_parser_result *parsed_input, t_command *command_info)
{
	if (tools)
	{
		if (tools->input)
			free(tools->input);
		if (tools->envp)
			free_string_array(tools->envp);
		if (tools->command_start && tools->command_len)
			free_size_string_array(tools->command_start, tools->command_len);
		free(tools);
	}
	if (parsed_input)
		parser_result_free(parsed_input);
	if (command_info && command_info->command_with_path)
		free(command_info->command_with_path);
	if (command_info && command_info->args)
		free_string_array(command_info->args);
	if (command_info)
		free(command_info);
	exit(exit_code);
}
