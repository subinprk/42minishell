/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:07:25 by subpark           #+#    #+#             */
/*   Updated: 2023/12/12 10:58:23 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	simple_cmd_action(t_cmd *cmd, int *pipefd, t_stdio *stdios, char **envp)
{
	int	builtin;

	if (stdios)
	{
		pipe_stdins(pipefd, stdios);
		pipe_stdouts(pipefd, stdios);
	}
	if (cmd->left_child)
	{
		builtin = check_builtin(cmd->left_child);
		if (builtin)
		{
			if (cmd->right_child)
				builtin_action(cmd->left_child, cmd->right_child->cmdstr);
			else
				builtin_action(cmd->left_child, NULL);
		}
		else
		{
			if (cmd->cmdstr)
				exec(cmd->cmdstr, envp);
			else
				exec(cmd->left_child->cmdstr, envp);
		}
	}
	else
		print_error_cmd(cmd->left_child, envp);
}

void	pipe_pipe(t_cmd *cmd, int *pipefd, t_stdio *stdios, char **envp)
{
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		simple_cmd_action(cmd, pipefd, stdios, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid, NULL, WNOHANG);
	}
}

void	pipe_end(t_cmd *cmd, int *pipefd, t_stdio *stdios, char **envp)
{
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
		dup2(pipefd[0], 0);
		waitpid(pid, NULL, WNOHANG);
	}
}