/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:41:37 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/27 12:04:52 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_output(char **output, char **temp)
{
	*temp = ft_strdup(*output);
	free(*output);
	*output = ft_strjoin(*temp, ft_itoa(getpid()));
	free(*temp);
}

/*
** @return a string with the name of the file, it makes sure its unique
*/
char	*name_gen(void)
{
	char	*output;
	int		fd;
	char	*temp;
	char	*str;

	str = ft_itoa(getpid());
	output = ft_strjoin("/tmp/", str);
	free(str);
	while (1)
	{
		fd = open(output, O_RDWR | O_CREAT | O_EXCL, 00644);
		if (fd != -1)
			break ;
		else if (fd == -1 && errno != EEXIST)
		{
			ft_error("open here_doc", NULL);
			return (NULL);
		}
		else if (fd == -1 && errno == EEXIST)
			set_output(&output, &temp);
		close(fd);
	}
	close(fd);
	return (output);
}

/* 
** reads input content with readline and writes it to fd
** @return 0 if it doesn't find a delimiter, 1 otherwise

*/
bool	read_line_cycle(char *del, char *line, int fd)
{
	line = readline("> ");
	if (!line)
	{
		ft_putstr_fd(
			"minishell: warning: here-document closed with EOF (wanted `", 2);
		ft_putstr_fd(del, 2);
		ft_putstr_fd("')\n", 2);
		return (1);
	}
	if (!ft_strncmp(line, del, ft_strlen(del) + 1))
	{
		free(line);
		return (1);
	}
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
	free(line);
	return (0);
}

void	heredoc_handler_stetup(t_tools	*tools, t_command *command,
		t_parser_result *parser_input)
{
	t_error_handling	*items;

	items = (t_error_handling *) malloc(sizeof(t_error_handling));
	items->command = command;
	items->tools = tools;
	items->parsed_input = parser_input;
	heredoc_handler(items, -42, NULL, 0);
}

/*
** @return the file descriptor of the file created
** with the content of the heredoc
*/
int	heredoc(char *del)
{
	int		fd;
	char	*line;
	char	*filename;

	line = NULL;
	if (!del)
		ft_error("syntax error near unexpected token `newline'", NULL);
	filename = name_gen();
	fd = open(filename, O_WRONLY);
	heredoc_handler(NULL, fd, filename, 0);
	signal(SIGINT, heredoc_signal);
	if (fd == -1)
		ft_error("open here_doc", NULL);
	while (1)
		if (read_line_cycle(del, line, fd))
			break ;
	close(fd);
	signal(SIGINT, signal_handler);
	fd = open(filename, O_RDONLY);
	unlink(filename);
	free(filename);
	return (fd);
}
