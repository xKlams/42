/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:05:50 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 23:04:29 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** checks if the file descriptor is valid
** @return -42 if the file descriptor is invalid
** @return -2 if the file descriptor is valid and dup2 was successful
*/
int	fd_redirect(char *file, int fd)
{
	int	changed_index;
	int	saved_char;

	if (file[ft_strlen(file) - 2] == '>' || file[ft_strlen(file) - 2] == '<')
		changed_index = ft_strlen(file) - 2;
	else
		changed_index = ft_strlen(file) - 1;
	saved_char = file[changed_index];
	file[changed_index] = '\0';
	if (ft_atoi(file) > 1023)
	{
		put_error("Bad file descriptor", file);
		file[changed_index] = saved_char;
		return (-42);
	}
	else
		dup2(fd, ft_atoi(file));
	file[changed_index] = saved_char;
	return (-2);
}

void	file_error(int fd, char *file)
{
	if (fd == -1)
	{
		if (errno == EACCES)
			put_error("Permission denied", file);
		else
			put_error("No such file or directory", file);
	}
}

/*
** TODO farsi passare il file descriptor precedente, se questo è
** valido allora chiudrelo
**
** @return -1 if an error occurred, fd of opened file otherwise
*/
int	set_fd(char **file, int open_flag, int i, t_command *command_info)
{
	int	fd;

	if (get_last_char(file[i]) == '>' && command_info->out_fd > 1)
		close(command_info->out_fd);
	if (get_last_char(file[i]) == '<' && command_info->in_fd > 0)
		close(command_info->in_fd);
	if (is_directory(file[i + 1]) && open_flag != O_RDONLY)
	{
		put_error(": Is a directory", file[i + 1]);
		return (-1);
	}
	fd = open(file[i + 1], open_flag, 00644);
	if (get_last_char(file[i]) == '<' || get_last_char(file[i]) == '>')
	{
		file_error(fd, file[i + 1]);
		return (fd);
	}
	else
		return (fd_redirect(file[i], fd));
}

void	redirection_routine(char **command, int i, t_command *command_info)
{
	if (ft_strlen(command[i]) > 1 && !ft_strncmp(command[i]
			+ ft_strlen(command[i]) - 2, "<<", 2) && command_info->in_fd != -1
		&& command_info->out_fd != -1)
		command_info->in_fd = heredoc(command[i + 1]);
	else if (command[i][0] && !ft_strncmp(command[i] + ft_strlen(command[i])
			- 1, "<", 1) && command_info->in_fd != -1 && command_info->out_fd !=
		-1)
		command_info->in_fd = set_fd(command, O_RDONLY, i, command_info);
	if (ft_strlen(command[i]) > 1 && !ft_strncmp(command[i]
			+ ft_strlen(command[i]) - 2, ">>", 2) && command_info->out_fd != -1
		&& command_info->in_fd != -1)
		command_info->out_fd = set_fd(command, O_WRONLY | O_APPEND | O_CREAT, i,
				command_info);
	else if (command[i][0] && !ft_strncmp(command[i] + ft_strlen(command[i])
			- 1, ">", 1) && command_info->out_fd != -1 && command_info->in_fd !=
		-1)
		command_info->out_fd = set_fd(command, O_WRONLY | O_CREAT | O_TRUNC, i,
				command_info);
}

/*
** sets every file_descriptor for command_info,
** if any is set to -41, an opening error occurred
*/
void	set_redirection(char **command, t_command *command_info,
		t_parser_result *parsed_info)
{
	int	i;

	i = 0;
	while (command[i] && (command[i][0] != '|' || parsed_info->quotes[i]))
	{
		if (count_words(command[i], ' ') > 1)
		{
			++i;
			continue ;
		}
		redirection_routine(command, i, command_info);
		i++;
	}
	if (command[i] && !ft_strncmp(command[i], "|", 2)
		&& command_info->out_fd == 1)
		command_info->out_fd = -42;
}
