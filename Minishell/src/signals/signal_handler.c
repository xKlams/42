/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:04:24 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 17:23:41 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int sig)
{
	static int	flag;

	if (sig == -42)
		flag = -1;
	if (sig == -41)
		flag = -2;
	if (sig < -40)
		return ;
	if (flag == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	exit_with_items(t_error_handling *items)
{
	t_command		*command;
	t_parser_result	*parsed_input;
	t_tools			*tools;

	command = NULL;
	parsed_input = NULL;
	tools = NULL;
	if (items)
	{
		if (items->command)
			command = items->command;
		if (items->parsed_input)
			parsed_input = items->parsed_input;
		if (items->tools)
			tools = items->tools;
		free(items);
	}
	exit_clean_up(tools, 130, parsed_input, command);
}

void	heredoc_handler(t_error_handling *items,
		int fd, char *string, bool delete)
{
	static t_error_handling	*saved_items;
	static int				fd_to_close;
	static char				*filename;

	if (!saved_items)
		saved_items = (t_error_handling *) malloc(sizeof(t_error_handling));
	if (delete)
	{
		close(fd_to_close);
		free(filename);
		exit_with_items(items);
	}
	if (items)
	{
		saved_items->command = items->command;
		saved_items->parsed_input = items->parsed_input;
		saved_items->tools = items->tools;
	}
	if (string)
		filename = string;
	if (fd != -42)
		fd_to_close = fd;
}

void	heredoc_signal(int sig)
{
	if (sig == 2)
	{
		write(2, "\n", 1);
		heredoc_handler(NULL, -42, NULL, 1);
	}
}
