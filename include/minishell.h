/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/12/01 17:03:35 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TOK_WORD 1
# define TOK_PIPE 2
# define TOK_REDIRET 3
# define TOK_S_QUOTE 4
# define TOK_D_QUOTE 5
# define TOK_NULL_HANDLE 0

# define NODE_PIPE 1
# define NODE_CMD 2
# define NODE_SIMPLE_CMD 3
# define NODE_FILE_PATH 4
# define NODE_ARGV 5
# define NODE_REDIRECTS 6
# define NODE_SIMPLE_REDIRECT 7
# define NODE_RED_TYPE 8
# define NODE_FILE_NAME 9
# define NODE_NULL_HANDLE 0

# define REL_TYPE_R 1
# define REL_TYPE_RR 2
# define REL_TYPE_L 3
# define REL_TYPE_LL 4

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
/*
typedef struct s_cmd 
{
	char	**cmdline;//should be the double array that can be used in execve func
	int		flag;
	char	quote;
}	t_cmd;*/
/*
typedef struct s_data
{
//	t_list	*lstlast;
//	t_cmd	*cmd;
//	t_data	*next;
//	t_data	*parent_node;
	struct s_data	*left_child;
	struct s_data	*right_child;
	char	*buf;*/
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
//}	t_data;

typedef struct s_cmd
{
	struct s_cmd	*left_child;
	struct s_cmd	*right_child;
	char				**cmdstr;
//	int					token;
	int					node_type;
	int					pipe_exist;
	int					pre_flag;
}	t_cmd;

typedef struct s_stdio
{
	int				re_type;
	char			*filename;
	struct s_stdio	*next_stdio;
}	t_stdio;

extern char	**g_envp;
extern int	g_exit_status;

//tools
void	free_2d(char **arr);
void	free_stdios(t_stdio *stdios);
int		array_length_2d(void **array);
char	**paths_array(char **envp);
void	exec(char **cmd, char **env);
int		*token_data(char **chopped_str);
int		find_pipe(int *token, int *i);
int		find_redirection(int *token, int *i);
void	find_rellocator(char *str, int *i, int *count);
void	find_spaces(char *str, int *i, int *count);
char	*strdup_rellocator(char *str, int *i);
char	*strdup_word(char *str, int *i);
int		composing_word(char c);
int		count_word_length(char *str, int start);
void	putting_words(char **word, char *str, int start, int length);
char	**text_array_part_cpy(char **line, int start, int end);
int		how_many_token_id(int *token, int token_identifier);


int		ft_strcmp(char *s1, char *s2);


//forks
char	*command_path(char **path_array, int i, char *command);
char	*path_pointer(char **envp, char *command);
void	exec(char **cmd, char **env);
void	search_tree(t_cmd *node, char **envp);
void	pipe_stdins(int *pipefd, t_stdio *stdios);
void	pipe_stdouts(int *pipefd, t_stdio *stdios);
void	print_error_cmd(t_cmd *file_path, char **envp);
int		check_builtin(t_cmd *file_path);
void	builtin_action(t_cmd *builtin, char **cmdline);
void	pipe_pipe(t_cmd *cmd, int *pipefd, t_stdio *stdios, char **envp);
void	pipe_end(t_cmd *cmd, int *pipefd, t_stdio *stdios, char **envp);

//parsing
char	**chopping_str(char *str);
t_cmd	*extract_command(char *str);
int		*token_data(char **chopped_str);
void	syntax_pipe(char **cmd_line, int *token, int *i, t_cmd *node);
void	syntax_cmds(char **cmd_line, int *token, int *i, t_cmd *node);
void	syntax_simple_cmd(char **cmd_line, int *token, int *i, t_cmd *node);
void	syntax_redirects(char **cmd_line, int *token, int *i, t_cmd *node);
void	syntax_simple_redirect(char **cmd_line, int *token, int *i, t_cmd *node);
t_cmd	*generate_tree_node(int node_type, int pipe_e);
t_cmd	*generate_end_node(char **line, int node_type, int start, int end);

// generate_prompt.c
void	generate_prompt(void);
int		read_from_stdin(char **buf);
int		get_line(char **line);

// parser.c
int        is_whitespace(char *c);


// utils.c
char	*ft_strnew(size_t size);
char	*get_env_value(char *key, char **envs);
int 	print_error(char *token, char *message);
int 	print_error2(char *token, char *token2, char *message);


int		find_pipe(int *token, int *i);
int		find_redirection(int *token, int *i);


// handle_signal.c
void    handle_signal(int sign);
void	set_signal(void);

#endif