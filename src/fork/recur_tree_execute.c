/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_tree_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:27 by subpark           #+#    #+#             */
/*   Updated: 2023/11/27 16:57:56 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_pipe()
{

}

void	execute_simple_cmd()
{

}

void	execute_simple_redirect()
{

}

void	execute_tree(t_cmd *node)
{
	if (node->node_type == NODE_CMD || node->node_type == NODE_REDIRECTS)
		return ;
	else if (node->node_type == NODE_PIPE)
		execute_pipe();
	else if (node->node_type == NODE_SIMPLE_CMD)
		execute_simple_cmd();
	else if (node->node_type == NODE_SIMPLE_REDIRECT)
		execute_simple_redirect();
}

void	search_tree(t_cmd *node)
{
	execute_tree(node);
	if (node->left_child != NODE_RED_TYPE ||
		node->left_child != NODE_FILE_PATH)
		search_tree(node->left_child);
	if (node->right_child != NODE_FILE_NAME ||
		node->right_child != NODE_ARGV)
		search_tree(node->right_child);
}