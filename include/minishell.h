/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:24:03 by subpark           #+#    #+#             */
/*   Updated: 2023/11/23 16:01:30 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define TOK_WORD 1
# define TOK_PIPE 2
# define TOK_RELLOCATE 3
# define TOK_S_QUOTE 4
# define TOK_D_QUOTE 5
# define TOK_NULL_HANDLE 0

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <limits.h>
# include <signal.h>

# include "../gnl/get_next_line.h"
# include "../gnl/ft_printf/ft_printf.h"
# include "../gnl/ft_printf/libft/libft.h"

typedef struct s_cmd 
{
	char	**cmdline;//should be the double array that can be used in execve func
	int		flag;
	char	quote;
}	t_cmd;

typedef struct s_data
{
	t_list	*lstlast;
	t_cmd	*cmd;
	t_data	*next;
	char	*buf;
//
/*	int		d_null;
	char	*prompt;
	int		current_index;
	int		args_index;
	int		args_count;
	int		*args_size;
	int		error;
	char	quote;
	char	**args_tmp;
	char	**args;*/
//Subin: I think some of them should be in different structure.
//t_data is a storage for a command input,
//it might be easier to understand
//if there is another structure only for generating prompt.
}	t_data;

void	free_2d(char **arr);
int		array_length_2d(void **array);
int		count_token(int *token, int token_identifier);
char	**paths_array(char **envp);
void	program_command(t_data data, char **envp);
void	act_p_command(t_data data, char **envp);
void	do_pipe(t_data data, char **envp);
void	exec(char **cmd, char **env);
int		*token_data(char **chopped_str);


// generate_prompt.c
void	generate_prompt(void);
int		read_from_stdin(char **buf);
int		get_line(char **line);

// parser.c
int        is_whitespace(char *c);


// utils.c
char	*ft_strnew(size_t size);

// handle_signal.c
void    handle_signal(int sign);
void	set_signal(void);

#endif