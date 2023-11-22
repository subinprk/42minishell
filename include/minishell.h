/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:24:03 by subpark           #+#    #+#             */
/*   Updated: 2023/11/22 18:21:33 by irivero-         ###   ########.fr       */
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
	char	**cmdline;
	int		flag;
	char	quote;
}	t_cmd;

typedef struct s_data
{
	t_list	*lstlast;
	t_cmd	*cmd;
	s_data	*next;
	char	*buf;
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
}	t_data;

#endif