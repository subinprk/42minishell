# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 12:51:28 by irivero-          #+#    #+#              #
#    Updated: 2023/08/09 16:30:06 by irivero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
HEADER = get_next_line.h

CFLAGS = -Wall -Werror -Wextra

YELLOW = \033[0;33m
PURPLE = \033[10;95m
RESET = \033[0m

CC = cc
#VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all\
#		--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes


FT_PRINTF = ft_printf/libftprintf.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME):$(OBJS)
		@echo "$(YELLOW)Making ft_printf.a...$(RESET)"
		make -C ft_printf
		@cp $(FT_PRINTF) $(NAME)
		@echo "$(YELLOW)Making libgnl.a...$(RESET)"
		ar rcs $(NAME) $(OBJS)
		norminette $(SRCS)

clean:	
	rm -f $(OBJS)
	@make clean -C ft_printf
	@echo "$(PURPLE)clean finished$(RESET)"

fclean: clean
	@make fclean -C ft_printf
	rm -f $(NAME)
	@echo "$(PURPLE)fclean finished$(RESET)"

re: fclean
	make all

PHONY: all clean fclean re
