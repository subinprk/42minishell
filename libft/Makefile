# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 18:40:02 by subpark           #+#    #+#              #
#    Updated: 2023/06/01 17:40:48 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Werror -Wextra

NAME = libft.a
SRC1 = ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
	ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c  ft_strrchr.c\
	ft_calloc.c ft_memchr.c   ft_putnbr_fd.c   ft_strlcat.c   ft_strtrim.c\
	ft_isalnum.c  ft_memcmp.c   ft_putstr_fd.c   ft_strlcpy.c   ft_substr.c\
	ft_isalpha.c  ft_memcpy.c   ft_split.c       ft_strlen.c    ft_tolower.c\
	ft_isascii.c  ft_memmove.c  ft_strchr.c      ft_strmapi.c   ft_toupper.c\
	ft_isdigit.c  ft_memset.c   ft_strdup.c      ft_strncmp.c
SRC2 = ft_lstadd_front_bonus.c	ft_lstlast_bonus.c	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c	ft_lstmap_bonus.c	ft_lstiter_bonus.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ1)
	ar r $(NAME) $(OBJ1)
	
bonus: $(OBJ1) $(OBJ2)
	ar r $(NAME) $(OBJ1) $(OBJ2)
	
%.o: %.c libft.h
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ1) $(OBJ2)

fclean: clean
	@rm -f $(NAME)

re: fclean all