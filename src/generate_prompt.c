/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:30:36 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/01 18:19:08 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**g_envp = NULL;
int		g_exit_status = 0;

/* generates and prints a command prompt to the standard output*/
void	generate_prompt(void)
{
	static char	*current_path;

	ft_putstr_fd("\033[1;32m", 1);
	ft_putstr_fd("our shell: ", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("\033[1;34m", 1);
	ft_putstr_fd(getcwd(current_path, 1024), 0);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("$ ", 1);
}

/* reads a line from standard input and appends it to the content of line
it uses a loop to keep reading util the end of input.
it returns the value of ret.*/
int		get_line(char **line)
{
	int		ret;
	char	*buf;
	char	*prompt;
	char	**tmp;

	generate_prompt();
	buf = readline("");
	tmp = cpy_full_2d_array(line);
	line = append_2d_array(line, tmp);
	free_2d(tmp);
	free(buf);
	/**line = ft_strdup("");
	while (1)
	{
		ret = read_from_stdin(&buf);
		tmp = ft_strjoin(*line, buf);
		free(*line);
		free(buf);
		*line = tmp;
		if (ret == 0)
		{
			ft_putstr_fd("exit\n", 1);
			if (ft_strlen(*line) != 0)
				continue;
			ft_putstr_fd("exit\n", 1);
		}	
		break ;
	}
	return (ret);*/
}

/* reads from standard input into the buffer*/
int		read_from_stdin(char **buf)
{
	int 	bytes_read;
	size_t	size;

	size = 1024;
	bytes_read = 0;
	*buf = ft_strnew(size);
	if (!buf)
		return (-1);
	bytes_read = read(0, *buf, size);
	if (bytes_read == 0)
	{
		free(*buf);
		return (-1);
	}
	else if (bytes_read < 0)
	{
		free(*buf);
		return (-1);
	}
	return (bytes_read);
}

