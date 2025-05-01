/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:31:42 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 18:08:46 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_quotes(char *s, char sep, size_t j)
{
	while (s[j] == '\'' || s[j] == '"')
	{
		sep = s[j];
		j++;
		while (s[j] != sep)
		{
			if (!s[j])
			{
				ft_putstr_fd("unmatched quote\n", STDERR_FILENO);
				return (0);
			}
			j++;
		}
		j++;
	}
	return (j);
}

/**
 * @note if does't match a separator before \0 returns NULL
 * @note i[0] = i, i[1] = j
 * @return next token from pointer
 */
static char	*next_token(char *s, size_t *off, int *last_exit_code)
{
	int		i[2];
	char	sep;

	sep = 0;
	i[0] = 0;
	while (s[i[0]] && s[i[0]] == ' ')
		i[0]++;
	if (s[i[0]] == '|')
		return (ft_strdup("|"));
	i[1] = handle_redirect(s, i[0]);
	if (i[1] == -1)
		return (handle_syntax_ret(last_exit_code));
	if (i[1] > i[0])
		return (ft_substr(s, i[0] + count(s, '0', off), i[1] - i[0] - count(s,
					'0', off)));
	while (s[i[1]] && s[i[1]] != ' ' && !is_exotic_char(s[i[1]]))
	{
		if (s[i[1]] == '\'' || s[i[1]] == '"')
			i[1] = handle_quotes(s, sep, i[1]);
		else
			i[1]++;
		if (!i[1])
			return (handle_syntax_ret(last_exit_code));
	}
	return (ft_substr(s, i[0], i[1] - i[0]));
}

void	ft_lst_utils(t_list **quote_tokens[2], bool *quoted, char **token)
{
	if (token == NULL)
		ft_lstadd_back(quote_tokens[0], ft_lstnew(ft_strdup("")));
	else
		ft_lstadd_back(quote_tokens[0], ft_lstnew(*token));
	ft_lstadd_back(quote_tokens[1], ft_lstnew(quoted));
}

void	*parse_while(char *input, t_tools *tools, int *last_exit_code,
		t_list **quote_tokens[2])
{
	size_t	i;
	size_t	offset;
	bool	*quoted;
	char	*token;

	i = 0;
	while (i < ft_strlen(input))
	{
		offset = 0;
		token = next_token(input + i, &offset, last_exit_code);
		if (!token)
			return (parser_handle_token_error(*quote_tokens));
		i += ft_strlen(token) + offset;
		while (input[i] && ft_strchr(" \t", input[i]))
			i++;
		quoted = token_has_quotes(token);
		token = preprocessed(token, tools, last_exit_code);
		if (!token && *quoted)
			ft_lst_utils(quote_tokens, quoted, NULL);
		else if (!token && !*quoted)
			free(quoted);
		else
			ft_lst_utils(quote_tokens, quoted, &token);
	}
	return (quote_tokens[0]);
}

/**
 * @note heap allocation
 * @note quote_tokens[0] = tokens, quote_tokens[1] = quotes
 * @param input: bash prompt
 * @param tools: the tools struct
 * @param last_exit_code
 * @warning hidden bug
 *
 * @return preprocessed input in t_parser_result *
 */
t_parser_result	*parse(char *input, t_tools *tools, int *last_exit_code)
{
	t_list	*quote_tokens[2];
	t_list	**quote_tokens_ptrs[2];

	quote_tokens[0] = NULL;
	quote_tokens[1] = NULL;
	quote_tokens_ptrs[0] = &quote_tokens[0];
	quote_tokens_ptrs[1] = &quote_tokens[1];
	while (input && ft_isspace(input[0]))
		input++;
	if (input && !pre_prompt_check(input))
		return (init_error_handler(input[0], last_exit_code));
	if (parse_while(input, tools, last_exit_code, quote_tokens_ptrs) == NULL)
		return (NULL);
	return (parser_build_result(quote_tokens[0], quote_tokens[1]));
}
