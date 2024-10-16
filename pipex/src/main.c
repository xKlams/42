/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:43:05 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/16 16:50:31 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	**params;
	int		files[2];

	if (argc != 5)
		return (0);
	fix_input(argv);
	paths = find_path(envp);
	if (paths == NULL)
	{
		ft_putstr_fd("bash: PATH enviroment variable not found\n", 2);
		return (EXIT_FAILURE);
	}
	initialize_params(params, argv);
	set_fd(files, params)
	set_params(argv, paths, params);
	ft_pipe(params, envp, (params[2] != NULL));
	return (EXIT_FAILURE);
}

void	initialize_params(char **params, char **argv)
{
	params = (char **)malloc(sizeof(char *) * 5);
	params[0] = ft_strdup(argv[1]);
	params[1] = NULL;
	params[2] = NULL;
	params[3] = ft_strdup(argv[4]);
	params[4] = NULL;
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
