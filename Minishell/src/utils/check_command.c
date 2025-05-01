/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:48:39 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/27 16:05:09 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	are_pipes_in_command(char **command)
{
	int	i;

	i = -1;
	while (command && command[++i])
	{
		if (!strncmp(command[i], "|", 2))
			return (true);
	}
	return (false);
}

bool	special_command_check(char **command)
{
	while (*command)
	{
		if (get_last_char(*command) == '>' || get_last_char(*command) == '<')
			command += 2;
		else
			break ;
	}
	if (ft_strncmp(*command, "exit", 5) == 0)
		return (true);
	if (ft_strncmp(*command, "cd", 3) == 0)
		return (true);
	if (ft_strncmp(*command, "export", 7) == 0)
		return (true);
	if (ft_strncmp(*command, "unset", 6) == 0)
		return (true);
	return (false);
}

static int	check_redirect_errors(t_parser_result *parser, int i)
{
	if (is_all_same_char(parser->command[i], get_last_char(parser->command[i]))
		&& ft_strlen(parser->command[i]) > 2)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putchar_fd(get_last_char(parser->command[i]), 2);
		ft_putchar_fd(get_last_char(parser->command[i]), 2);
		ft_putstr_fd("'\n", 2);
		return (EXIT_FAILURE);
	}
	if (parser->command[i + 1] == NULL)
	{
		ft_putstr_fd("minishell: syntax error near ", 2);
		ft_putstr_fd("unexpected token `newline'\n", 2);
		return (EXIT_FAILURE);
	}
	else if (get_last_char(parser->command[i + 1]) == '<'
		|| get_last_char(parser->command[i + 1]) == '>'
		|| get_last_char(parser->command[i + 1]) == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putchar_fd(parser->command[i + 1][0], 2);
		ft_putstr_fd("'\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_pipe_errors(t_parser_result *parser, int i)
{
	if ((parser->command[i + 1] == NULL && !parser->quotes[i])
		|| (parser->command[i + 1] && parser->command[i + 1][0] == '|'))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_valid_command(t_parser_result *parser)
{
	int	i;
	int	ret;

	i = -1;
	while (parser->command && parser->command[++i])
	{
		if (count_words(parser->command[i], ' ') > 1
			|| ft_strlen(parser->command[i]) == 0)
			continue ;
		if (get_last_char(parser->command[i]) == '<'
			|| get_last_char(parser->command[i]) == '>')
		{
			ret = check_redirect_errors(parser, i);
			if (ret != EXIT_SUCCESS)
				return (ret);
		}
		if (get_last_char(parser->command[i]) == '|')
		{
			ret = check_pipe_errors(parser, i);
			if (ret != EXIT_SUCCESS)
				return (ret);
		}
	}
	return (EXIT_SUCCESS);
}
