/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:24:03 by subpark           #+#    #+#             */
/*   Updated: 2023/11/23 03:55:05 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <limits.h>

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
	int		d_null;
	char	*prompt;
	int		current_index;
	int		args_index;
	int		args_count;
	int		*args_size;
	int		error;
	char	quote;
	char	**args_tmp;
	char	**args;
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

#endif