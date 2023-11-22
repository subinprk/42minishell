/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_child_pro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:46:48 by subpark           #+#    #+#             */
/*   Updated: 2023/11/22 18:05:46 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	act_p_command(t_data data, char **envp)
{
	pid_t	pid;

	if (data.cmd->flag == 1)
	{
		do_pipe(data, envp);
	}
	
	
}

void	program_command(t_data data, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
		act_p_command(data, envp);
	else
		waitpid(pid, NULL, WNOHANG);
}