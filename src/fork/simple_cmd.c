/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:07:25 by subpark           #+#    #+#             */
/*   Updated: 2023/12/01 16:54:30 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	simple_cmd_action(t_cmd *cmd, int *pipefd, t_stdio *stdios, char **envp)
{
	int	builtin;

	if (!stdios)
	{
		pipe_stdins(pipefd, stdios);
		pipe_stdouts(pipefd, stdios);
	}
	builtin = check_builtin(cmd->left_child);
	if (builtin)
		builtin_action(cmd->right_child);
	else
		exec(cmd->cmdstr, envp);
}

void	pipe_pipe(t_cmd *cmd, int *pipefd, t_stdio *stdios, char **envp)
{
	int		fd;
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
	{
		close(pipefd[0]);
		fd = dup2(pipefd[1], 1);
		simple_cmd_action(cmd, pipefd, stdios, envp);
	}
	else
	{
		close(pipefd[1]);
		fd = dup2(pipefd[0], 0);
		waitpid(pid, NULL, WNOHANG);
	}
}

void	pipe_end(t_cmd *cmd, int *pipefd, t_stdio *stdios, char **envp)
{
	int		fd;
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		simple_cmd_action(cmd, pipefd, stdios, envp);
	}
	else
	{
		close(pipefd[1]);
		fd = dup2(pipefd[0], 0);
		waitpid(pid, NULL, WNOHANG);
	}
}