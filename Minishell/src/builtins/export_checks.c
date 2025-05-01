/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:24:45 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/26 20:05:06 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *str, int ret)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (ret);
}

int	check_joined_string(char **aux, char ***envp, char *joined_sting)
{
	if (joined_sting)
	{
		add_env_var(aux[0], joined_sting, envp);
		free(joined_sting);
	}
	else
		add_env_var(aux[0], aux[1], envp);
	free_string_array(aux);
	return (2);
}

/*
** checks if syntax of export is correct
** @returns 0 if correct, 1 if incorrect, 2 if correct with +
*/
int	export_check(char **command, char ***envp)
{
	int		i;
	char	**aux;
	char	*joined_sting;
	int		index;

	i = -1;
	if (command[1][0] == '=' || ft_isdigit(command[1][0]) || command[1][0] == 0)
		return (print_error(command[1], 1));
	while (command[1][++i] && command[1][i] != '=')
	{
		if (command[1][i] == '-' || (command[1][i] == '+' && command[1][i
				+ 1] != '='))
			return (print_error(command[1], 1));
		else if (command[1][i] == '+' && command[1][i + 1] == '=')
		{
			aux = ft_split(command[1], '=');
			index = ft_strlen(aux[0]) - 1;
			aux[0][index] = '\0';
			joined_sting = ft_strjoin(get_value_envp(aux[0], *envp), aux[1]);
			aux[0][index] = '=';
			return (check_joined_string(aux, envp, joined_sting));
		}
	}
	return (0);
}

void	swap_var(char **strings, int j, char *temp, int *swapped)
{
	temp = strings[j];
	strings[j] = strings[j + 1];
	strings[j + 1] = temp;
	*swapped = 1;
}

void	bubble_sort(char *strings[], int n)
{
	int		i;
	int		j;
	int		swapped;
	char	*temp;

	temp = NULL;
	if (strings == NULL || n <= 0)
		return ;
	i = 0;
	while (i < n - 1)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_strncmp(strings[j], strings[j + 1], max_strlen(strings[j],
						strings[j + 1])) > 0)
				swap_var(strings, j, temp, &swapped);
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}
