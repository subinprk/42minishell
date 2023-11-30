/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:51:03 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 20:32:13 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_action(t_cmd *builtin, char **envp)
{
	if (builtin->cmdstr[0] == "echo")
		our_echo(builtin->cmdstr, envp);
	if (builtin->cmdstr[0] == "cd")
		;
	if (builtin->cmdstr[0] == "pwd")
		;
	if (builtin->cmdstr[0] == "export")
		;
	if (builtin->cmdstr[0] == "unset")
		;
	if (builtin->cmdstr[0] == "env")
		;
	if (builtin->cmdstr[0] == "exit")
		;
}

void	simple_cmd_action(t_cmd *cmd, int *pipefd, int builtin, char **envp)
{
	int	fd[2];

	fd[0] = 0;
	fd[1] = dup2(pipefd[1], 1);
	if (fd[1] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(pipefd[0]);
		return ;
	}
	close(pipefd[0]);
	if (builtin)
		builtin_action(cmd->right_child, envp);
	else
		execve(cmd->right_child->cmdstr[0], cmd->left_child->cmdstr, envp);
	exit(errno);
}

void	simple_cmd_connect(int *pipefd)
{
	int	fd[2];

	fd[0] = dup2(pipefd[0], 0);
	fd[1] = 1;//meaningless

	if (fd[0] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(pipefd[1]);
		exit(errno);
	}
	close(pipefd[1]);
}

int		check_builtin(t_cmd *file_path)
{
	if (file_path->cmdstr[0] == "echo" || file_path->cmdstr[0] == "cd"
		|| file_path->cmdstr[0] == "pwd" || file_path->cmdstr[0] == "export"
		|| file_path->cmdstr[0] == "unset" || file_path->cmdstr[0] == "env"
		|| file_path->cmdstr[0] == "exit")
		return (1);
	else
		return (0);
}
/*
void	simple_cmd(t_cmd *cmd, char **envp)
{
	int		pipefd[2];
	int		builtin;
	pid_t	pid;

	builtin = check_builtin(cmd->left_child);
	if (!builtin)
		print_error_cmd(cmd->left_child, envp);
	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
		simple_cmd_action(cmd, pipefd, builtin, envp);
	else
	{
		waitpid(pid, NULL, WNOHANG);
		simple_cmd_connect(pipefd);
	}
}*/