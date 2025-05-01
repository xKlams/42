/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:52:47 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/28 17:50:22 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	initialize_shell(t_tools **tool, char **enviroment)
{
	*tool = (t_tools *)ft_calloc(1, sizeof(t_tools));
	if (!*tool)
		return (EXIT_FAILURE);
	(*tool)->last_exit_code = 0;
	copy_envp(*tool, enviroment);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	set_shell_level(&((*tool)->envp));
	return (EXIT_SUCCESS);
}

char	*get_input(t_tools *tool)
{
	char	*input;
	char	*mini;

	signal_handler(-42);
	mini = get_ministr(tool);
	input = readline(mini);
	free(mini);
	signal_handler(-41);
	if (!input)
	{
		rl_clear_history();
		ft_putstr_fd("exit\n", 2);
		ft_exit(NULL, tool, NULL);
	}
	if (!*input)
	{
		free(input);
		return (NULL);
	}
	add_history(input);
	return (input);
}

int	main(int argc, char **argv, char **enviroment)
{
	t_tools	*tool;
	char	*input;

	if (argc != 1 && argv)
	{
		ft_putstr_fd("Error: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (initialize_shell(&tool, enviroment) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (1)
	{
		input = get_input(tool);
		if (input == NULL)
			continue ;
		process_command(&input, tool);
	}
	return (0);
}
