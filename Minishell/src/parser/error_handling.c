/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:35:56 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/27 18:04:41 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	diff_char_handler(char *sub, char *to_free)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `",
		STDERR_FILENO);
	ft_putchar_fd(sub[0], STDERR_FILENO);
	if (sub[1])
		ft_putchar_fd(sub[1], STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	free(to_free);
	return (false);
}

bool	exceeded_count_handler(char *sub, char last_char, char *to_free)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `",
		STDERR_FILENO);
	ft_putchar_fd(last_char, STDERR_FILENO);
	if (sub[1] && sub[1] == last_char)
		ft_putchar_fd(last_char, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	free(to_free);
	return (false);
}

void	*init_error_handler(char c, int *last_exit_code)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `",
		STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	*last_exit_code = -42;
	return (NULL);
}

bool	pre_prompt_check(char *s)
{
	if (!s)
		return (false);
	if (!*s)
		return (true);
	if (ft_strchr("|;", *s))
		return (false);
	if (ft_strlen(s) > 1)
		return (true);
	if (ft_strchr("<>", *s))
		return (false);
	return (true);
}
