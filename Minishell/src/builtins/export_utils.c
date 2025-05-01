/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:20:54 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/26 19:27:23 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	max_strlen(char *str1, char *str2)
{
	if (ft_strlen(str1) > ft_strlen(str2))
		return (ft_strlen(str1));
	else
		return (ft_strlen(str2));
}

char	**alloc_failure(char **duparray, int index)
{
	int	j;

	j = 0;
	while (j < index)
	{
		free(duparray[j]);
		j++;
	}
	free(duparray);
	return (NULL);
}

char	**dup_str_array(char *strings[], int n)
{
	char	**duparray;
	int		i;

	if (strings == NULL || n <= 0)
		return (NULL);
	duparray = (char **)malloc(n * sizeof(char *));
	if (duparray == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		duparray[i] = ft_strdup(strings[i]);
		if (duparray[i] == NULL && strings[i] != NULL)
			return (alloc_failure(duparray, i));
		i++;
	}
	return (duparray);
}

int	check_if_already_set(char *name, char ***envp, int i)
{
	if (!ft_strncmp(name, (*envp)[i], ft_strchr(name, '=') - name)
		&& ((ft_strchr(name, '=') - name) == ft_strchr((*envp)[i], '=')
			- (*envp)[i] || !ft_strchr((*envp)[i], '=')))
	{
		free((*envp)[i]);
		(*envp)[i] = ft_strdup(name);
		return (1);
	}
	return (0);
}

/*add a variable to our copy of envp*/
void	just_add(char *variable, char ***envp)
{
	int		i;
	char	**new_envp;

	i = -1;
	while ((*envp)[++i])
		if (!ft_strncmp(variable, (*envp)[i], ft_strlen(variable))
			&& ((*envp)[i][ft_strlen(variable)] == '='
				|| (*envp)[i][ft_strlen(variable)] == 0))
			return ;
	new_envp = (char **)malloc((i + 2) * sizeof(char *));
	new_envp[i + 1] = NULL;
	i = -1;
	while ((*envp)[++i])
	{
		new_envp[i] = ft_strdup((*envp)[i]);
		free((*envp)[i]);
	}
	new_envp[i] = ft_strdup(variable);
	free(*envp);
	*envp = new_envp;
}
