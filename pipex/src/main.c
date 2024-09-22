/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:43:05 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/23 00:13:00 by fde-sist         ###   ########.fr       */
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
	params = set_params(argv, paths);
	if (!ft_pipe(params, envp))
		return (0);
}
