/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:23:53 by subpark           #+#    #+#             */
/*   Updated: 2023/11/23 02:34:46 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	left_pipe(t_data data, int *pipefd, char **envp)
{
	int	fd[2];

	fd[0] = 0;
	fd[1] = dup2(pipefd[1], 1);
	if (fd[0] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(pipefd[0]);
		exit (errno);
		return ;
	}
	close(pipefd[0]);
	exec((data.cmd)->cmdline, envp);
	exit(errno);
}

void	right_pipe(t_data data, int	*pipefd, char **envp)
{
	int fd[2];

	if (pipefd[1] < 0)
		exit(1);
	fd[0] = dup2(pipefd[0], 0);
	fd[1] = 1;
	if (fd[1] == -1)
	{
		close(fd[1]);
		close(fd[0]);
		close(pipefd[1]);
		exit (errno);
	}
	close(pipefd[1]);
	act_p_command(data, envp);
	return ;
}

void	do_pipe(t_data data, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
		left_pipe(data, pipefd, envp);
	else
	{
		waitpid(pid, NULL, WNOHANG);
		right_pipe(*(data.next), pipefd, envp);
	}
//	act_p_command(*(data.next), envp);
}

/*
	command on left pipe:
		execved directly
		send result to pipe(to the right side of pipe, right pipe function)
	command on right pipe:
		execved by recalling act_p_command(recursive, left pipe function)
		read input from pipe(from the left side of pipe)
*/