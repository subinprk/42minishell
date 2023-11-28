/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_execute_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:13:03 by subpark           #+#    #+#             */
/*   Updated: 2023/11/28 18:16:50 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	redirect_type(t_cmd *node)
{
	if (node->cmdstr[0] == "<")
		return (REL_TYPE_L);
	else if (node->cmdstr[0] == "<<")
		return (REL_TYPE_LL);
	else if (node->cmdstr[0] == ">")
		return (REL_TYPE_R);
	else if (node->cmdstr[0] == ">>")
		return (REL_TYPE_RR);
}

void	redirect_l_connect(int re_type, t_cmd *file_name, int *pipefd)
{
	int	fd[2];
	int	filefd;

	if (re_type == REL_TYPE_L)
	{
		filefd = open(file_name->cmdstr[0], O_RDONLY);
		if (!filefd)
			close_two_exit(pipefd[0], pipefd[1]);
		re_type_l_pipes(fd, pipefd);
	}
	else if (re_type == REL_TYPE_LL)
	{
		filefd = open(file_name->cmdstr[0], O_CREAT | O_RDWR, 0666);
		if (!filefd)
			close_two_exit(pipefd[0], pipefd[1]);
		re_type_l_pipes(fd, pipefd);
	}
}

void	redirect_r_connect(int re_type, t_cmd *file_name, int *pipefd)
{
	int	fd[2];
	int	filefd;

	if (re_type == REL_TYPE_R)
	{
		filefd = open(file_name->cmdstr[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (!filefd)
			close_two_exit(pipefd[0], pipefd[1]);
		re_type_r_pipes(fd, pipefd);
	}
	else if (re_type == REL_TYPE_RR)
	{
		filefd = open(file_name->cmdstr[0], O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (!filefd)
			close_two_exit(pipefd[0], pipefd[1]);
		re_type_r_pipes(fd, pipefd);
	}

}

void connect_command(int re_type, int *pipefd, char **envp)
{
	int	fd[2];

	if (re_type == REL_TYPE_L)
	{

	}
	else if (re_type == REL_TYPE_LL)//?? didn't get the concept of HereDoc indicator
	{

	}
	else if (re_type == REL_TYPE_R)
	{

	}
	else if (re_type == REL_TYPE_RR)
	{
		
	}
}