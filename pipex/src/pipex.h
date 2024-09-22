/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:50:12 by fde-sist          #+#    #+#             */
/*   Updated: 2024/09/23 00:07:36 by fde-sist         ###   ########.fr       */
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

void	child(int pipefd[2], int files[2], char **envp, char **params);
void	father(int pipefd[2], int files[2], char **envp, char **params);
int		ft_max(int a, int b);
void	fix_input(char **argv);
char	**find_path(char **envp);
void	write_error(char *error_message, char *file_name, int *flag);
int		set_fd(int files[2], char **params);
int		ft_pipe(char **params, char **envp);
char	**set_params(char **argv, char **paths);

#endif