# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siun <siun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 15:14:43 by irivero-          #+#    #+#              #
#    Updated: 2023/12/04 20:44:27 by siun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBS = libgnl.a
LIBS_DIR = gnl
LIBS_PATH = gnl/libgnl.a

CFLAGS = -Wall -Werror -Wextra

GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

CC = cc
VALGRIND = @valgrind --leak-check=full

SRCS_DIR = ./src/

SRCS = $(addprefix $(SRCS_DIR),  fork/exec_func_tools.c \
 fork/recur_tree_execute.c \
 fork/simple_cmd.c\
 fork/simple_cmd_stdins.c\
 fork/simple_cmd_stdouts.c\
 fork/simple_cmd_tools.c\
 parsing/get_a_command.c\
 parsing/lexical_analysis.c\
 parsing/tree_node_gen.c\
 parsing/chopping_str.c\
 parsing/syntax_analysis.c\
 tools/array_length.c\
 tools/copy_2d_arr.c\
 tools/chopping_str_tool.c\
 tools/chopping_word_tools.c\
 tools/check_token_existence.c\
 tools/ft_strcmp.c\
 tools/free_tools.c\
 tools/get_envpath.c\
 builtins/cd.c\
 builtins/echo.c\
 builtins/env.c\
 builtins/exit.c\
 builtins/export.c\
 builtins/pwd.c\
 builtins/unset.c\
 handle_signal.c\
 utils.c\
 generate_prompt.c\
 utils2.c\
 main.c)

OBJS = $(SRCS:.c=.o)

all : $(NAME) $(LIBS_PATH)

$(NAME): $(OBJS) 
	@echo "$(GREEN)\nmaking libft...ft_printf...GNL...$(RESET)"
	@make -C $(LIBS_DIR)
	@cp -r $(LIBS_PATH) $(NAME)
	$(CC) $(SRCS) $(LIBS_PATH) $(CFLAGS) -o $(NAME) 
	#ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)\nmandatory norminette$(RESET)"
	@norminette $(SRCS)

clean: 
	@rm -f $(OBJS)
	@echo "$(BLUE)\ncleaning libft...ft_printf...GNL...$(RESET)"
	@make clean -C $(LIBS_DIR)
	
fclean: clean
	@echo "$(BLUE)\nfcleaning libft...ft_printf...GNL...$(RESET)"
	@make fclean -C $(LIBS_DIR)
	@rm -f $(NAME)

re: fclean
	@make all

run: $(NAME) 
	$(VALGRIND) ./$(NAME)

PHONY: all clean fclean re run