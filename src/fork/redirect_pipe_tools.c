/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_pipe_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:41:10 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 20:17:36 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_two_exit(int *fd1, int *fd2)
{
	close(fd1);
	close(fd2);
	exit(errno);
}

void	re_type_r_pipes(int *pipefd, int filefd)
{
	int	fd[2];

	fd[0] = dup2(pipefd[0], 0);
	fd[1] = dup2(filefd, 1);
	if (fd[0] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(pipefd[1]);
		exit(errno);
	}
	close(pipefd[1]);
}

void	re_type_l_pipes(int *pipefd, int filefd)
{
	int	fd[2];
	
	fd[0] = dup2(filefd, 0);
	fd[1] = dup2(pipefd[1], 1);
	if (fd[1] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(pipefd[0]);
		exit(errno);
	}
	close(pipefd[0]);
}

void	connect_re_l_pipes(int *fd, int *pipefd)
{
	int	fd[2];

	fd[0] = dup2(pipefd[0], 0);
	fd[1] = 1;
	if (fd[0] == -1);
	{
		close(fd[0]);
		close(fd[1]);
		close(pipefd[1]);
		exit(errno);
	}
	close(pipefd[1]);
}

void	connect_re_r_pipes(int *fd, int *pipefd)
{
	int	fd[2];

	fd[0] = 0;
	fd[1] = dup2(pipefd[1], 1);
	if (fd[1] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		cloes(pipefd[0]);
		exit(errno);
	}
	close(pipefd[0]);
}