/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_stdins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:54:07 by siun              #+#    #+#             */
/*   Updated: 2023/12/01 02:24:21 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heredoc_input(int filefd, char *word)
{
	char	*line;

	line = readline("heredoc> ");
	while (ft_strcmp(line, word) != 0)
	{
		write(filefd, line, ft_strlen(line));
		write(filefd, "\n", 1);
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
}

void	re_type_l_pipes(int filefd)
{	
	int	fd;

	fd = dup2(filefd, 0);
	if (fd == -1)
		exit(errno);
}

void	connect_stdins(t_stdio *last_in)
{
	int	filefd;

	if (last_in->re_type == REL_TYPE_L)
	{
		filefd = open(last_in->filename, O_RDONLY);
		if (!filefd)
			exit(errno);
		re_type_l_pipes(filefd);
	}
	else if (last_in->re_type == REL_TYPE_LL)//have to make heredoc
	{
		filefd = open(last_in->filename, O_CREAT | O_RDWR, 0666);//making tmp file
		if (!filefd)
			exit(errno);
		heredoc_input(filefd, last_in->filename);
		re_type_l_pipes(filefd);///have to remove tmp file, have to think about it later
	}
}

void    pipe_stdins(int *pipefd, t_stdio *stdios)
{
	t_stdio	*last_in;
	t_stdio	*curr;

	last_in = NULL;
	curr = stdios;
	while (!curr)
	{
		if (curr->re_type == REL_TYPE_L || curr->re_type == REL_TYPE_LL)
			last_in == curr;
		curr = curr->next_stdio;
	}
	if (last_in != NULL)
		connect_stdins(last_in);
}