/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:47 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/26 22:34:33 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_tilde(char *s, t_tools *tools, size_t *i)
{
	if (ft_strlen(s) > 1 && s[1] == '/')
	{
		*i += 2;
		return (ft_strjoin(get_value_envp("HOME", tools->envp), "/"));
	}
	*i += 1;
	return (ft_strdup(get_value_envp("HOME", tools->envp)));
}

void	handle_quotes(bool *inside_2quotes, size_t *i)
{
	*inside_2quotes = !*inside_2quotes;
	(*i)++;
}

static char	*hadle_single_quotes(char *s, char *out, size_t *i)
{
	*i += 1;
	while (s[*i])
	{
		if (s[*i] == '\'')
		{
			*i += 1;
			return (out);
		}
		out = join_char(out, s[*i]);
		*i += 1;
	}
	return (NULL);
}

void	preprocessed_utils(char *s, t_tools *tools, int *last_exit_code,
		char **out)
{
	size_t	i;
	bool	inside_2quotes;

	i = 0;
	inside_2quotes = false;
	if (s && s[i] == '~')
		*out = expand_tilde(s, tools, &i);
	else
		*out = ft_strdup("");
	while (s && s[i])
	{
		if (s[i] == '"')
			handle_quotes(&inside_2quotes, &i);
		else if (s[i] == '\'' && !inside_2quotes)
			*out = hadle_single_quotes(s, *out, &i);
		else if (s[i] == '$' && s[i + 1] && s[i + 1] == '?')
		{
			*out = joinfree(*out, ft_itoa(*last_exit_code), true, true);
			i += 2;
		}
		else if (s[i] == '$')
			*out = env_processing(s + i, *out, &i, tools);
		else
			*out = join_char(*out, s[i++]);
	}
}

char	*preprocessed(char *s, t_tools *tools, int *last_exit_code)
{
	char	*out;

	out = NULL;
	preprocessed_utils(s, tools, last_exit_code, &out);
	free(s);
	if (out[0] == '\0')
	{
		free(out);
		return (NULL);
	}
	return (out);
}
