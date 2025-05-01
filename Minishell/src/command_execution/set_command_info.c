/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_command_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:17:18 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 15:51:48 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dup_output(char **output, int *j, t_parser_result *parsed_input, int *i)
{
	if ((get_last_char(parsed_input->command[*i]) != '<'
			&& get_last_char(parsed_input->command[*i]) != '>')
		|| parsed_input->quotes[*i])
	{
		output[(*j)] = ft_strdup(parsed_input->command[*i]);
		(*j) += 1;
	}
	else
		(*i) += 1;
}

/*
** @return a string array with all the commands that do not contain a redirection
*/
char	**command_setup(t_parser_result *parsed_input)
{
	int		i;
	int		j;
	char	**output;

	i = 0;
	j = 0;
	if (!parsed_input->command)
		return (NULL);
	output = (char **)malloc(sizeof(char *) * (len_no_redirect(parsed_input)
				+ 1));
	while (parsed_input->command[i] && (parsed_input->command[i][0] != '|'
		|| parsed_input->quotes[i]))
	{
		if (parsed_input->quotes[i])
		{
			output[j++] = ft_strdup(parsed_input->command[i]);
			i++;
			continue ;
		}
		dup_output(output, &j, parsed_input, &i);
		i++;
	}
	output[j] = NULL;
	return (output);
}

/*
** @return t_command * to all the information needed
**  to execute execve with pipe and redirections
**
** commnad->in_fd = -42 means you have to handle here doc
**
** commnad->out_fd = -42 means you have to redirect with pipe
*/
t_command	*set_command_info(t_parser_result *parsed_input, t_tools *tools)
{
	t_command	*output;
	char		**paths;

	output = (t_command *)ft_calloc(1, sizeof(t_command));
	output->out_fd = STDOUT_FILENO;
	set_redirection(parsed_input->command, output, parsed_input);
	paths = find_path(tools->envp, 0);
	output->args = command_setup(parsed_input);
	output->command_with_path = set_command(output->args, paths, tools->envp);
	free_string_array(paths);
	return (output);
}
