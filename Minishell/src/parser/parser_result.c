/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:35:50 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/27 17:51:17 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser_result	*parser_result_init(char **arr, bool *quotes)
{
	t_parser_result	*result;

	result = (t_parser_result *)ft_calloc(1, sizeof(t_parser_result));
	if (!result)
		return (NULL);
	result->command = arr;
	result->quotes = quotes;
	return (result);
}

void	parser_result_free(t_parser_result *result)
{
	free(result->quotes);
	free(result);
}
