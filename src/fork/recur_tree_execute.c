/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_tree_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:53:44 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 21:24:33 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_simple_cmd(t_cmd *cmd, t_stdio *stdios, char **envp)
{
	int		builtin;

	builtin = check_builtin(cmd->left_child);
	if (!builtin)
		print_error_cmd(cmd->left_child, envp);
	simple_cmd_action();
	if (cmd->pipe_exist != -1)

}

void	execute_tree(t_cmd *node, t_stdio *stdios, char **envp)
{
	if (node->node_type == NODE_CMD || node->node_type == NODE_REDIRECTS)
		return ;
	else if (node->node_type == NODE_PIPE)
		execute_pipe(node, envp);
	else if (node->node_type == NODE_SIMPLE_CMD)
		execute_simple_cmd(node, envp, stdios);
	else if (node->node_type == NODE_SIMPLE_REDIRECT)
		execute_simple_redirect(node, envp);
}

void	search_tree(t_cmd *node, char **envp)
{
	t_stdio	stdios;

	execute_tree(node, stdios, envp);
	if ((node->left_child != NODE_RED_TYPE ||
		node->left_child != NODE_FILE_PATH) && node->left_child)
		search_tree(node->left_child, envp);
	if ((node->right_child != NODE_FILE_NAME ||
		node->right_child != NODE_ARGV) && node->right_child)
		search_tree(node->right_child, envp);
}