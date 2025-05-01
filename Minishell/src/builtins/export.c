/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:00:02 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/28 17:40:08 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	utils(char *new_string, char **envp)
{
	while (*envp)
	{
		new_string = ft_strdup(*envp);
		if (ft_strchr(new_string, '='))
		{
			*(ft_strchr(new_string, '=') + 1) = 0;
			printf("declare -x %s", new_string);
			free(new_string);
		}
		else
		{
			printf("declare -x %s\n", *envp);
			free(new_string);
			envp++;
			continue ;
		}
		new_string = ft_strchr(*envp, '=');
		if (!new_string)
			printf("=\"\"\n");
		else
			printf("\"%s\"\n", new_string + 1);
		envp++;
	}
}

int	export_no_args(char **in_envp)
{
	char	*new_string;
	char	**envp;
	char	**envp_start;

	envp = dup_str_array(in_envp, string_array_size(in_envp) + 1);
	bubble_sort(envp, string_array_size(envp));
	envp_start = envp;
	new_string = NULL;
	utils(new_string, envp);
	free_string_array(envp_start);
	return (EXIT_SUCCESS);
}

void	export_variable(char *name, char ***envp)
{
	int		i;
	char	**new_envp;

	i = -1;
	while ((*envp)[++i])
		if (check_if_already_set(name, envp, i))
			return ;
	if ((*envp)[i] != NULL)
		return ;
	new_envp = (char **)malloc((i + 2) * sizeof(char *));
	new_envp[i + 1] = NULL;
	i = -1;
	while ((*envp)[++i])
	{
		new_envp[i] = ft_strdup((*envp)[i]);
		free((*envp)[i]);
	}
	new_envp[i] = ft_strdup(name);
	free(*envp);
	*envp = new_envp;
}

/*
** takes as an input a command and enviroment variables,
** adds enviroment variable to the list
*/
int	export(char **command, char ***envp)
{
	int	lenght;
	int	i;
	int	check_value;

	lenght = 0;
	while (command[lenght])
		lenght++;
	if (lenght < 2)
		return (export_no_args(*envp));
	check_value = export_check(command, envp);
	if (check_value == 1)
		return (EXIT_FAILURE);
	if (check_value == 2)
		return (EXIT_SUCCESS);
	i = 0;
	while (++i < lenght)
	{
		if (ft_strchr(command[i], '='))
			export_variable(command[i], envp);
		else
			just_add(command[i], envp);
	}
	return (EXIT_SUCCESS);
}
