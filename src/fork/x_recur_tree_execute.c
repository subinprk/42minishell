/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_tree_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:27 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 20:34:20 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_pipe(t_cmd *node, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
	{

	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		//connect_command(pipefd, envp);
	}
}

//subin :maybe it could be better not to do fork for simple cmd, let's see later
void	execute_simple_cmd(t_cmd *cmd, char **envp)
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
}

void	execute_simple_redirect(t_cmd *node, char **envp)
{
	pid_t	pid;
	int		pipefd[2];
	int		type;

	type = redirect_type(node->left_child);
	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
		redirect_connect(type, node->right_child, pipefd);
	else
	{
		waitpid(pid, NULL, WNOHANG);
		connect_command_redir(type, pipefd);
	}
}
void	execute_tree(t_cmd *node, char **envp)
{
	if (node->node_type == NODE_CMD || node->node_type == NODE_REDIRECTS)
		return ;
	else if (node->node_type == NODE_PIPE)
		execute_pipe(node, envp);
	else if (node->node_type == NODE_SIMPLE_CMD)
		execute_simple_cmd(node, envp);
	else if (node->node_type == NODE_SIMPLE_REDIRECT)
		execute_simple_redirect(node, envp);
}

void	search_tree(t_cmd *node, char **envp)
{
	execute_tree(node, envp);
	if ((node->left_child != NODE_RED_TYPE ||
		node->left_child != NODE_FILE_PATH) && node->left_child)
		search_tree(node->left_child, envp);
	if ((node->right_child != NODE_FILE_NAME ||
		node->right_child != NODE_ARGV) && node->right_child)
		search_tree(node->right_child, envp);
}