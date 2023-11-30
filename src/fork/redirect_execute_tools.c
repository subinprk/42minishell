/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_execute_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:13:03 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 20:28:33 by subpark          ###   ########.fr       */
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
	else if (re_type == REL_TYPE_LL)//have to make heredoc
	{
		filefd = open(file_name->cmdstr[0], O_CREAT | O_RDWR, 0666);//making tmp file
		if (!filefd)
			close_two_exit(pipefd[0], pipefd[1]);
		heredoc_input(filefd, file_name->cmdstr[0]);
		re_type_l_pipes(fd, pipefd);///have to remove tmp file, have to think about it later
	}
}

void	redirect_r_connect(int re_type, t_cmd *file_name, int *pipefd)
{
	int	filefd;

	if (re_type == REL_TYPE_R)
	{
		filefd = open(file_name->cmdstr[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (!filefd)
			close_two_exit(pipefd[0], pipefd[1]);
		re_type_r_pipes(pipefd, filefd);
	}
	else if (re_type == REL_TYPE_RR)
	{
		filefd = open(file_name->cmdstr[0], O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (!filefd)
			close_two_exit(pipefd[0], pipefd[1]);
		re_type_r_pipes(pipefd, filefd);
	}

}

void	redirect_connect(int re_type, t_cmd *node, int *pipefd)
{
	if (re_type == REL_TYPE_L || re_type == REL_TYPE_LL)
		redirect_l_connect(re_type, node, pipefd);
	else if (re_type == REL_TYPE_R || re_type == REL_TYPE_RR)
		redirect_r_connect(re_type, node, pipefd);
}

void	connect_command_redir(int re_type, int *pipefd)
{
	if (re_type == REL_TYPE_L || re_type == REL_TYPE_LL)
		connect_re_l_pipes(pipefd);
	else if (re_type == REL_TYPE_R || re_type == REL_TYPE_RR)
		connect_re_r_pipes(pipefd);
}