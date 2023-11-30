/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:07:25 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 21:24:00 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    pipe_pipe(t_cmd *cmd, char **envp)
{

}

void    pipe_stdios(int *pipefd, t_stdio *stdios)
{

}

void    simple_cmd_action(t_cmd *cmd, t_stdio *stdios, char **envp)
{
	int     pipefd[2];
	int		builtin;
	pid_t   pid;
	
	builtin = check_builtin(cmd->left_child);
	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
		simple_cmd_action(cmd, pipefd, builtin, envp);
	if (stdios != NULL)
		pipe_stdios(pipefd, stdios);
}