/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:43:05 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/24 01:32:07 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	**params;

	if (argc != 5)
		return (0);
	fix_input(argv);
	paths = find_path(envp);
	if (paths == NULL)
	{
		ft_putstr_fd("bash: PATH enviroment variable not found\n", 2);
		return (EXIT_FAILURE);
	}
	params = set_params(argv, paths);
	return (!ft_pipe(params, envp, !(params[1] != NULL && params[2] != NULL)));
}

void	print_str_array(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		ft_putstr_fd(str_array[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
}
