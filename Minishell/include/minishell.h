/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:33:26 by mgenoves          #+#    #+#             */
/*   Updated: 2025/02/28 17:52:41 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define _GNU_SOURCE
# include "../libs/libft/libft.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>

/* STRUCTS */
typedef struct s_tools
{
	char						**envp;
	char						*input;
	char						**command_start;
	int							command_len;
	int							last_exit_code;
}								t_tools;

typedef struct s_command
{
	char						**args;
	char						*command_with_path;
	int							in_fd;
	int							out_fd;
}								t_command;

typedef struct s_parser_result
{
	char						**command;
	bool						*quotes;
}								t_parser_result;

typedef struct s_error_handling
{
	t_tools			*tools;
	t_command		*command;
	t_parser_result	*parsed_input;
}					t_error_handling;

/* SIGNAL HANDLING */
void							signal_handler(int sig);
void							sigchld_handler(int sig);
void							heredoc_signal(int sig);

/* COMMAND EXEC*/
int								is_command(char *command, char **paths);
char							*set_command(char **command, char **paths,
									char **envp);
int								is_path(char *command);
char							*path_command(char **command, char **envp);
void							absolute_path_case(char **command,
									char **output);
int								execute_command(t_tools *tools,
									t_parser_result *parsed_input);
int								is_special_command(char **command);
char							**find_path(char **envp, int index);
int								next_command_index(
									t_parser_result *parsed_input);
void							child_process(t_tools *tools,
									t_parser_result *parsed_input,
									int pipefd[2]);
int								parent_process(int pid, int pipefd[2],
									t_parser_result *parsed_input);
int								invalid_command(char **command,
									char *command_with_path);
int								command_error_handler(t_command *command_info,
									int pipefd[2]);
t_command						*set_command_info(t_parser_result *parsed_input,
									t_tools *tools);
int								heredoc(char *del);
bool							is_builtin(char *command);
void							execute_builtin(t_parser_result *parsed_input,
									t_tools *tool, char **command,
									t_command *command_info);
void							heredoc_handler(t_error_handling *items,
									int fd_to_close, char *filename,
									bool delete);
void							heredoc_handler_stetup(t_tools	*tools,
									t_command *command,
									t_parser_result *parser_input);

/* ENV FNCS*/
void							copy_envp(t_tools *tools, char **envp);
void							add_env_var(char *key, char *value,
									char ***envp);
char							*get_value_envp(char *name, char **envp);
void							set_shell_level(char ***envp);

/* BUILTINS */
int								pwd(void);
int								cd(char **command, t_tools *tools);
int								env(char **envp, char **command);
int								echo(char **command);

void							ft_exit(t_parser_result *parsed_input,
									t_tools *tool,
									char **command);
void							unset_target(char *target, char ***envp);
int								unset(char **targets, char ***envp);
int								export(char **command, char ***envp);
void							export_variable(char *name, char ***envp);
int								export_no_args(char **envp);
size_t							max_strlen(char *str1, char *str2);
char							**alloc_failure(char **duparray, int index);
char							**dup_str_array(char *strings[], int n);
int								check_if_already_set(
									char *name, char ***envp, int i);
void							just_add(char *variable, char ***envp);
int								export_check(char **command, char ***envp);
void							bubble_sort(char *strings[], int n);

/* PARSER */
bool							pre_prompt_check(char *s);
t_parser_result					*parser_result_init(char **arr, bool *quotes);
void							parser_result_free(t_parser_result *result);
t_parser_result					*parse(char *input, t_tools *tools,
									int *last_exit_code);
void							*parser_handle_token_error(
									t_list *quote_tokens[2]);
char							*env_processing(char *s, char *dest, size_t *i,
									t_tools *tools);
char							*join_char(char *s, char c);
char							*joinfree(char *s, char *s2, bool fs, bool fs2);
t_parser_result					*parser_build_result(struct s_list *l,
									struct s_list *quotes);
char							*preprocessed(char *s, t_tools *tools,
									int *last_exit_code);
bool							is_parser_separator(char c);
bool							is_exotic_char(char c);
int								handle_redirect(char *s, int j);
bool							*token_has_quotes(char *s);
void							*init_error_handler(
									char c, int *last_exit_code);
bool							diff_char_handler(char *sub, char *to_free);
bool							exceeded_count_handler(char *sub,
									char last_char, char *to_free);
void							*handle_syntax_ret(int *last_exit_code);
size_t							count(char *s, char c, size_t *offset);

// UTILS
int								ft_n_args(char **command);
void							cleanup(char *input);
void							free_string_array(char **str);
void							ft_error(char *error_type, char **command);
int								is_directory(const char *path);
void							free_size_string_array(char **array,
									size_t size);
void							exit_clean_up(t_tools *tools, int exit_code,
									t_parser_result *parsed_input,
									t_command *command_info);
void							print_string_array(char **str);
char							get_last_char(char *str);
size_t							string_array_size(char **array);
int								len_no_redirect(t_parser_result *strs);
void							put_error(char *str, char *error);
void							set_redirection(char **command,
									t_command *command_info,
									t_parser_result *parsed_info);
void							print_string_array(char **str);
void							free_size_string_array(char **array,
									size_t size);

// MAIN UTILS
char							*get_ministr(t_tools *tool);
size_t							string_array_size(char **array);
bool							is_all_same_char(char *str, char c);
bool							are_pipes_in_command(char **command);
bool							special_command_check(char **command);
int								check_valid_command(t_parser_result *parser);
int								handle_special_command(
									t_parser_result *parsed_input,
									char *input, t_tools *tool,
									t_command *command_info);
void							process_command(char **input, t_tools *tool);

#endif
