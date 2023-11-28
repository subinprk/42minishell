/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_pipe_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:41:10 by subpark           #+#    #+#             */
/*   Updated: 2023/11/28 17:59:45 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	re_type_l_pipes(int *fd, int *pipefd, int filefd)
{
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

void	re_type_r_pipes(int *fd, int *pipefd, int filefd)
{
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
