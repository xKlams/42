/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:48:54 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 17:18:21 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Takes command with args and flags, envp, and exectutes it*/
int	execute_command(t_tools *tools, t_parser_result *parsed_input)
{
	pid_t	pid;
	int		pipefd[2];
	int		last_exit;
	int		std_in_fd[2];

	std_in_fd[0] = dup(STDIN_FILENO);
	std_in_fd[1] = dup(STDOUT_FILENO);
	while (*parsed_input->command)
	{
		if (pipe(pipefd) == -1)
			ft_error("pipe", parsed_input->command);
		pid = fork();
		if (pid == -1)
			ft_error("pid", parsed_input->command);
		if (pid == 0)
			child_process(tools, parsed_input, pipefd);
		last_exit = parent_process(pid, pipefd, parsed_input);
		tools->last_exit_code = last_exit;
		parsed_input->command += next_command_index(parsed_input);
	}
	while (wait(0) != -1)
		;
	dup2(std_in_fd[0], STDIN_FILENO);
	dup2(std_in_fd[1], STDOUT_FILENO);
	return (last_exit);
}

/*
** @return index of next pipe, if not found returns end of command
*/
int	next_command_index(t_parser_result *parsed_input)
{
	int	i;

	i = 0;
	while (parsed_input->command[i])
	{
		if (parsed_input->command[i][0] == '|' && !parsed_input->quotes[i])
			break ;
		i++;
	}
	if (parsed_input->command[i] && (parsed_input->command[i + 1] == NULL
			|| parsed_input->command[i][0] == '|'))
		return (i + 1);
	return (i);
}
