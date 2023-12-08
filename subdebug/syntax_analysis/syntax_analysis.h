#ifndef SYNTAX_ANALYSIS_H
# define SYNTAX_ANALYSIS_H

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
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>

# include "../libft/libft.h"

typedef struct s_cmd
{
	struct s_cmd	*left_child;
	struct s_cmd	*right_child;
	char				**cmdstr;
//	int					token;
	int					node_type;
	int					pipe_exist;
}	t_cmd;

#endif