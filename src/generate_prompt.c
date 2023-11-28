/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:30:36 by irivero-          #+#    #+#             */
/*   Updated: 2023/11/28 10:47:39 by irivero-         ###   ########.fr       */
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
	char	*tmp;

	*line = ft_strdup("");
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
	return (ret);
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
/*
void	exec_minishell(t_data *data)
{
	//check if command is a redirection or a pipe
	//if not, printf error

	//else loop
	//end loop

}
*/
int		main(int argc, char **argv, char **envp)
{
	int		ret;
	
	ret = 1;
	while (ret)
	{
		generate_prompt();

	}
	return (0);
}