/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:43:05 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 12:10:50 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	**params;
	int		files[2];

	if (argc != 5)
	{
		ft_putstr_fd("Error: Wrong amount of arguments\n", 2);
		return (0);
	}
	fix_input(argv);
	paths = find_path(envp);
	if (paths == NULL)
	{
		ft_putstr_fd("zsh: PATH enviroment variable not found\n", 2);
		return (EXIT_FAILURE);
	}
	params = initialize_params(argv);
	if (set_fd(files, params))
		return (EXIT_FAILURE);
	set_params(argv, paths, params);
	error_handler(params[1], params[2], files[0], argv);
	return (ft_pipe(params, envp, files));
}
