# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 15:14:43 by irivero-          #+#    #+#              #
#    Updated: 2023/12/07 18:29:52 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT		= libft.a
LIBFT_DIR	= libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

CCFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lreadline

GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

CC = cc

SRCS_DIR = src/

SRCS = src/builtins/unset.c src/builtins/env.c src/builtins/cd.c\
 src/builtins/echo.c\
 src/builtins/exit.c\
 src/builtins/export.c\
 src/builtins/pwd.c\
 src/fork/exec_func_tools.c\
 src/fork/recur_tree_execute.c\
 src/fork/simple_cmd.c\
 src/fork/simple_cmd_stdins.c\
 src/fork/simple_cmd_stdouts.c\
 src/fork/simple_cmd_tools.c\
 src/handle_signal.c\
 src/parsing/chopping_str.c\
 src/parsing/get_a_command.c\
 src/parsing/lexical_analysis.c\
 src/parsing/syntax_analysis.c\
 src/parsing/tree_node_gen.c\
 src/tools/free_tools.c\
 src/tools/ft_strcmp.c\
 src/tools/get_envpath.c\
 src/tools/array_length.c\
 src/tools/check_token_existence.c\
 src/tools/chopping_str_tool.c\
 src/tools/chopping_word_tools.c\
 src/tools/copy_2d_arr.c\
 src/generate_prompt.c\
 src/main.c\
 src/utils.c\
 src/utils2.c\
 \
 subdebug/node_check.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
			rm -f $(OBJS)
			make clean -C $(LIBFT_DIR)
fclean: clean
			rm -f $(NAME)
			rm -f $(LIBFT)
re: fclean all

%.o: %.c include/minishell.h
			$(CC) $(CCFLAGS) -c $< -o $@
$(LIBFT):
			make bonus -C $(LIBFT_DIR)
			mv $(LIBFT_DIR)/$(LIBFT) .

$(NAME): $(OBJS) $(LIBFT)
			$(CC) $(CCFLAGS) $(LDFLAGS) -o $@ $^ -lreadline
.PHONY: all clean fclean re