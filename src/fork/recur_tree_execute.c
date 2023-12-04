/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_tree_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:53:44 by subpark           #+#    #+#             */
/*   Updated: 2023/12/04 20:04:59 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_simple_cmd(t_cmd *cmd, t_stdio *stdios, char **envp)
{
	int		pipefd[2];
	int		builtin;

	builtin = check_builtin(cmd->left_child);
	if (!builtin)
		print_error_cmd(cmd->left_child, envp);
	if (cmd->pipe_exist != -1)
		pipe_pipe(cmd, pipefd, stdios, envp);
	else
		pipe_end(cmd, pipefd, stdios, envp);
	free_stdios(stdios);
	stdios = NULL;
}

void	execute_simple_redirect(t_cmd *node, t_stdio *stdios)
{
	t_stdio	*redirection;
	t_stdio *curr;

	redirection = (t_stdio *)malloc(sizeof(t_stdio));
	if (stdios == NULL)
	{
		redirection->filename = node->right_child->cmdstr[0];
		redirection->re_type = redirect_type(node->left_child);
		redirection->next_stdio = NULL;
	}
	else
	{
		redirection->filename = node->right_child->cmdstr[0];
		redirection->re_type = redirect_type(node->left_child);
		redirection->next_stdio = NULL;
		curr = stdios;
		while (curr->next_stdio)
			curr = curr->next_stdio;
		curr->next_stdio = redirection;
	}
}

void	execute_tree(t_cmd *node, t_stdio *stdios, char **envp)
{
	if (node->node_type == NODE_CMD || node->node_type == NODE_REDIRECTS)
		return ;
	else if (node->node_type == NODE_PIPE)
		//execute_pipe(node, envp);
		;
	else if (node->node_type == NODE_SIMPLE_CMD)
		execute_simple_cmd(node, stdios, envp);
	else if (node->node_type == NODE_SIMPLE_REDIRECT)
		execute_simple_redirect(node, stdios);
}

void	search_tree(t_cmd *node, char **envp)
{
	static t_stdio	*stdios;

	execute_tree(node, stdios, envp);
	if ((node->left_child->node_type != NODE_RED_TYPE ||
		node->left_child->node_type != NODE_FILE_PATH) && node->left_child)
		search_tree(node->left_child, envp);
	if ((node->right_child->node_type != NODE_FILE_NAME ||
		node->right_child->node_type != NODE_ARGV) && node->right_child)
		search_tree(node->right_child, envp);
}