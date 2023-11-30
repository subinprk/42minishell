/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_connect_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:18:13 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 15:49:39 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    re_connecc_l_pipes(int re_type, int *pipefd)
{
	int	fd[2];

	fd[0] = dup2(pipefd[0], 0);
	fd[1] = 1;
	if (fd[1] == -1);
	{
		close(fd[1]);
		close(fd[0]);
		close(pipefd[1]);
		exit(errno);
	}
	close(pipefd[1]);
	//subin: have to think about connecting to next one
	//I think it's wrong direction, but it's kinda complex,
	//think about it later after simple cmd
}

void    re_connect_r_pipes()
{
	int	fd[2];

	fd[0] = 
}