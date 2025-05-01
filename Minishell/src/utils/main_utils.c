/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:41:02 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/27 15:48:11 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_ministr(t_tools *tool)
{
	char	*pwd;
	char	*user;
	char	*temp;
	char	*cwd;

	if (!get_value_envp("HOME", tool->envp) || !get_value_envp("USER",
			tool->envp))
		return (ft_strdup("minishell: "));
	temp = ft_strdup(get_value_envp("USER", tool->envp));
	user = ft_strjoin(temp, "@:");
	free(temp);
	cwd = getcwd(NULL, 0);
	if (ft_strncmp(cwd, get_value_envp("HOME", tool->envp), ft_strlen(cwd)) == 0
		&& (ft_strlen(cwd) == ft_strlen(get_value_envp("HOME", tool->envp))))
		temp = ft_strdup("~");
	else
		temp = ft_strdup(ft_strrchr(cwd, '/'));
	pwd = ft_strjoin(temp, "$ ");
	free(temp);
	temp = ft_strjoin(user, pwd);
	free(user);
	free(pwd);
	free(cwd);
	return (temp);
}

size_t	string_array_size(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

bool	is_all_same_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (false);
		i++;
	}
	return (true);
}
