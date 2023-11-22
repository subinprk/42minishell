# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 15:14:43 by irivero-          #+#    #+#              #
#    Updated: 2023/11/22 15:19:31 by irivero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBS = libgnl.a
LIBS_DIR = gnl
LIBS_PATH = gnl/libgnl.a

GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

SRCS_DIR = ./src/

SRCS = $(addprefix $(SRCS_DIR), //add source archives names)

OBJS = $(SRCS: .c=.o)

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