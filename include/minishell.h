/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:52:41 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/01 18:17:17 by subpark          ###   ########.fr       */
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

//builtins

//cd
int		cd_to_home_directory(char *current_path, char **cmdline, char **envs);
int		cd_to_env_variable(char *current_path, char **cmdline, char **envs);
void	update_pwd_variables(char **envs);
void	change_directory(char **cmdline, char **envs);

//echo
void	exit_status(void);
void	echo_env_variable(char **cmdline, char **envs, int i);
int		is_option_n(char *token);
void	our_echo(char **cmdline, char **envs);

//env
void    env(char **args);

//exit
void    exit_err(void);
void    exit_command(t_cmd *cmd, char **cmdline);

//export
void    print_export(char **env);
int     is_valid_export_key(char *key);
void	add_export_variable(char *str, char **new, int i);
int		update_or_add_export(char *str, char ***env);
void    execute_export_command(t_cmd *cmd, char **cmdline);

//pwd
void    our_pwd(void);

//unset
int 	is_valid_env_variable_name (char *str);
int		check_env_variable(char *key, char *env);
int 	unset_enviroment_variable(char *key, char ***env);
void    execute_unset_command(t_cmd *cmd, char **cmdline);

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
char	**cpy_full_2d_array(char **origin);
char	**append_2d_array(char **origin, char *line);
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

// get_envpath.c
char	**paths_array(char **envp);

// generate_prompt.c
void	generate_prompt(void);
int		read_from_stdin(char **buf);
int		get_line(char **line);

// utils.c
char	*ft_strnew(size_t size);
char	*get_env_value(char *key, char **envs);
int 	print_error(char *token, char *message);
int 	print_error2(char *token, char *token2, char *message);
int		print_id_error(char *token, char *message);

//utils2.c
int		remove_char(char *str, char c);
int		double_char_len(char **str);
int		is_stringdigit(char *str);
int     is_whitespace(char *c);

int		find_pipe(int *token, int *i);
int		find_redirection(int *token, int *i);


// handle_signal.c
void    handle_signal(int sign);
void	set_signal(void);

#endif