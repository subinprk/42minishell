/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_stdouts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:07:41 by siun              #+#    #+#             */
/*   Updated: 2023/12/14 17:02:53 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	re_type_r_pipes(int **fd, int filefd, int *pipefd)
{
	*(fd[1]) = dup2(filefd, pipefd[1]);
	if (*(fd[1]) == -1)
	{
		close(*(fd[0]));
		close(*(fd[1]));
		exit(errno);
	}
}

void	connect_stdouts(int **fd, t_stdio *last_out, int *pipefd)
{
	int	filefd;

	filefd = -1;
	if (last_out->re_type == REL_TYPE_R)
	{
		filefd = open(last_out->filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (!filefd)
			exit(errno);
		re_type_r_pipes(fd, filefd, pipefd);
	}
	else if (last_out->re_type == REL_TYPE_RR)
	{
		filefd = open(last_out->filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (!filefd)
			exit(errno);
		re_type_r_pipes(fd, filefd, pipefd);
	}
	close(filefd);
}

void	pipe_stdouts(int *pipefd, t_stdio *stdios)
{
	t_stdio	*last_out;
	t_stdio	*curr;

	last_out = NULL;
	curr = stdios;
	while (curr)
	{
		if (curr->re_type == REL_TYPE_R || curr->re_type == REL_TYPE_RR)
			last_out = curr;
		curr = curr->next_stdio;
	}
	if (last_out != NULL)
		connect_stdouts(&pipefd, last_out, pipefd);
}