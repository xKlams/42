/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:50:12 by fde-sist          #+#    #+#             */
/*   Updated: 2024/10/17 00:34:07 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_command
{
	char	*bin;
	char	**flag;
}		t_command;

char	**initialize_params(char **argv);
char	**find_path(char **envp);
void	fix_input(char **argv);
int		set_fd(int files[2], char **params);
void	set_params(char **argv, char **paths, char **output);
int		child(int pipefd[2], int files[2], char **envp, char **params);
int		parent(int pipefd[2], int files[2], char **envp, char **params);
int		ft_pipe(char **params, char **envp, int files[2]);
int		second_command(char **params, char **envp, int files[2]);
int		standard_behaviour(char **params, char **envp, int files[2]);
void	free_str_array(char **str_array, int len);
int		ft_max(int a, int b);
void	write_error(char *error_message, char *file_name);
void	error_handler(char *first, char *second, int flag, char **argv);

#endif