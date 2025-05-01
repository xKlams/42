# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 11:55:48 by fde-sist          #+#    #+#              #
#    Updated: 2025/02/28 17:49:10 by fde-sist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
SRCS = src/main.c src/builtins/cd.c src/builtins/pwd.c src/builtins/env.c src/builtins/echo.c src/builtins/export.c src/builtins/export_utils.c src/builtins/export_checks.c src/builtins/unset.c src/builtins/exit.c \
	   src/env/envp.c src/env/add_env_var.c src/env/set_shell_level.c \
	   src/parser/parse.c src/parser/quote_utils.c src/parser/parser_utils.c src/parser/preprocessing.c src/parser/exotic_char_utils.c src/parser/env_preprocessing.c src/parser/parser_result.c src/parser/error_handling.c\
	   src/memory_managment/free_string_array.c \
	   src/command_execution/command_checks.c src/command_execution/find_path.c src/command_execution/execute_command.c src/command_execution/command_setting.c src/command_execution/set_command_info.c src/command_execution/fork_processes.c src/command_execution/heredoc.c src/command_execution/invalid_command.c src/command_execution/builtin_execution.c src/command_execution/redirections.c src/command_execution/command_execution_utils.c\
	   src/signals/signal_handler.c \
	   src/utils/main_utils.c src/utils/check_command.c src/utils/handle_special_command.c src/utils/process_command.c
CFLAGS = -Wall -Wextra -Werror -gdwarf-4 -Wuninitialized  -g

LIBFT_DIR = ./libs/libft
HEADERS = -I./include -I$(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a
LINK = -lreadline -lncurses $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(HEADERS) $(SRCS) $(LINK) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

clean:
	@rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

valgrind: all
	valgrind --leak-check=full -s ./$(NAME)

.PHONY: all clean fclean re
