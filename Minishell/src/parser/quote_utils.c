/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:34:21 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/26 22:36:18 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline bool	is_parser_separator(char c)
{
	return (c == ' ' || c == '\'' || c == '"');
}

inline bool	*token_has_quotes(char *s)
{
	bool	*quotes;

	if (!s)
		return (ft_calloc(1, sizeof(bool)));
	if (ft_strlen(s) < 2)
		return (ft_calloc(1, sizeof(bool)));
	quotes = ft_calloc(ft_strlen(s), sizeof(bool));
	*quotes = ((s[0] == '"' && s[ft_strlen(s) - 1] == '"') || (s[0] == '\''
				&& s[ft_strlen(s) - 1] == '\''));
	return (quotes);
}
