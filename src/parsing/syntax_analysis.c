/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:40:29 by siun              #+#    #+#             */
/*   Updated: 2023/11/27 13:21:06 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	syntax_pipe(char **cmd_line, int *token, int *i, t_cmd *node)
{
	int	pipe_index;
	int	tmp;

	tmp = i[1];
	node = generate_tree_node(NODE_CMD);
	pipe_index = find_pipe(token, i);;
	if (pipe_index != -1)
		i[1] = pipe_index;
	syntax_cmds(cmd_line, token, i, node->left_child);
	if (pipe_index != -1)
	{
		i[0] = pipe_index;
		i[1] = tmp;
		syntax_pipe(cmd_line, token, pipe_index, node->right_child);
	}
}

void	syntax_cmds(char **cmd_line, int *token, int *i, t_cmd *node)
{
	int	redirect_index;
	int	tmp;

	tmp = i[1];
	node = generate_tree_node(NODE_REDIRECTS);
	redirect_index = find_redirection(token, i);
	if (redirect_index != -1)
		i[1] = redirect_index;
	syntax_simple_cmd(cmd_line, token, i, node->left_child);
	if (redirect_index != -1)
	{
		i[0] = redirect_index;
		i[1] = tmp;
		syntax_redirects(cmd_line, token, redirect_index, node->right_child);
	}
}

void	syntax_simple_cmd(char **cmd_line, int *token, int *i, t_cmd *node)
{
	node = generate_tree_node(NODE_SIMPLE_CMD);
	node->left_child = generate_end_node(cmd_line, NODE_FILE_PATH, i[0],i[0] + 1);
	node->right_child = generate_end_node(cmd_line, NODE_ARGV, i[0], i[1]);
}

void	syntax_redirects(char **cmd_line, int *token, int *i, t_cmd *node)
{
	int	redirect_index;
	int	tmp;

	tmp = i[1];
	redirect_index = find_redirection(token, i);
	if (redirect_index != -1)
		i[1] = redirect_index;
	syntax_simple_redirect(cmd_line, token, i, node->left_child);
	if (redirect_index != -1)
	{
		i[0] = redirect_index;
		i[1] = tmp;
		syntax_redirects(cmd_line, token,redirect_index, node->right_child);
	}
}

void	syntax_simple_redirect(char **cmd_line, int *token, int *i, t_cmd *node)
{
	node = generate_tree_node(NODE_SIMPLE_REDIRECT);
	node->left_child = generate_end_node(cmd_line, NODE_RED_TYPE,
						i[0], i[0] + 1);
	node->right_child = generate_file_name_node(cmd_line, NODE_FILE_NAME,
						i[0] + 1, i[1]);
}