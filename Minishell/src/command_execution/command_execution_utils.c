/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executions_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:14:25 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 12:14:35 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @return first occurance of '>', '<', or '|'
** if its not found returns last index of command
*/
int	special_char_index(char **command)
{
	int	i;

	i = -1;
	while (command[++i])
	{
		if (command[i][0] == '|' || command[i][0] == '>'
			|| command[i][0] == '<')
			return (i);
	}
	return (i);
}

/*
** outputs to standard error "minishell: {error}: {str}\n"
*/
void	put_error(char *str, char *error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

/*
** @return the last char of a string
*/
char	get_last_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (0);
	return (str[i - 1]);
}

/*
**	@returns the number of strings in strs that do not contain a redirection
*/
int	len_no_redirect(t_parser_result *strs)
{
	int	i;
	int	output;

	i = 0;
	output = 0;
	if (!strs)
		return (0);
	while (strs->command[i] && (strs->command[i][0] != '|' || strs->quotes[i]))
	{
		if (count_words(strs->command[i], ' ') > 1)
		{
			output++;
			i++;
			continue ;
		}
		if ((get_last_char(strs->command[i]) != '<'
				&& get_last_char(strs->command[i]) != '>') || strs->quotes)
			output++;
		else
			i++;
		i++;
	}
	return (output);
}
