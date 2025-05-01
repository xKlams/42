/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_preprocessing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:00:08 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/27 11:46:55 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_sep_index(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (s[0] && s[0] == '$')
		i++;
	while (s[i])
	{
		if (is_parser_separator(s[i]) || s[i] == '$' || (!ft_isalnum(s[i])
				&& s[i] != '_'))
			return (i);
		i++;
	}
	return (i);
}

static char	*handle_non_existent(char *s, char *dest, size_t *i)
{
	size_t	sep_indx;
	char	*out;

	sep_indx = get_sep_index(s);
	if (s[1] && s[2] && ft_isdigit(s[1]))
	{
		out = ft_substr(s, 2, sep_indx - 2);
		*i += sep_indx;
		return (joinfree(dest, out, false, true));
	}
	*i += sep_indx;
	return (ft_strdup(dest));
}

char	*env_processing(char *s, char *dest, size_t *i, t_tools *tools)
{
	char	*out;
	char	*env;
	size_t	sep_indx;
	char	*temp;

	sep_indx = get_sep_index(s);
	if (sep_indx == 1)
	{
		*i += 1;
		return (join_char(dest, '$'));
	}
	temp = ft_substr(s, 1, sep_indx - 1);
	env = get_value_envp(temp, tools->envp);
	if (!env)
	{
		free(temp);
		out = handle_non_existent(s, dest, i);
		free(dest);
		return (out);
	}
	free(temp);
	out = joinfree(dest, ft_strdup(env), true, true);
	*i += sep_indx;
	return (out);
}

void	*handle_syntax_ret(int *last_exit_code)
{
	*last_exit_code = -42;
	return (NULL);
}

size_t	count(char *s, char c, size_t *offset)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == c)
		i++;
	*offset = i;
	return (i);
}
