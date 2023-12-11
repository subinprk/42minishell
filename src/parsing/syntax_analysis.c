/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:40:29 by siun              #+#    #+#             */
/*   Updated: 2023/12/11 15:31:42 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	syntax_pipe(char **cmd_line, int *token, int *i, t_cmd *node)
{
	int		pipe_index;
	int		tmp;
	t_cmd	*head_tmp;

	head_tmp = node;
	tmp = i[1];
	pipe_index = find_pipe(token, i);
	node = generate_tree_node(NODE_CMD, pipe_index);
	if (pipe_index != -1)
	{
		i[1] = pipe_index;
		if (pipe_index == i[0])
		{
			perror("syntax error near unexpected token '|'\n");
			return (-1);
		}
	}
	if (syntax_cmds(cmd_line, token, i, node->left_child) == -1)
		return (-1);
	if (pipe_index != -1)
	{
		i[0] = pipe_index + 1;
		i[1] = tmp;
		return (syntax_pipe(cmd_line, token, i, node->right_child));
	}
	node = head_tmp;
	return (1);
}

int	syntax_cmds(char **cmd_line, int *token, int *i, t_cmd *node)
{
	int	redirect_index;
	int	tmp;
	t_cmd	*head_tmp;

	head_tmp = node;
	tmp = i[1];
	node = generate_tree_node(NODE_REDIRECTS, -1);
	redirect_index = find_redirection(token, i);
	if (redirect_index != -1)
		i[1] = redirect_index;
	if (redirect_index == i[0])
	{
		perror("syntax error near unexpected token");
		return (-1);
	}
	if (syntax_simple_cmd(cmd_line, i, token, node->left_child) == -1)
		return (-1);
	if (redirect_index != -1)
	{
		i[0] = redirect_index;
		i[1] = tmp;
		return (syntax_redirects(cmd_line, token, i, node->right_child));
	}
	node = head_tmp;
	return (1);
}

int	syntax_simple_cmd(char **cmd_line, int *i, int *token, t_cmd *node)
{
	int		pipe_check[2];
	int		pipe_e;
	t_cmd	*head_tmp;

	head_tmp = node;
	pipe_check[0] = i[1];
	pipe_check[1] = token_length(token);
	pipe_e = find_pipe(token, pipe_check);
	node = generate_tree_node(NODE_SIMPLE_CMD, pipe_e);
	node->left_child = generate_end_node(cmd_line, NODE_FILE_PATH, i[0], i[0] + 1);
	node->right_child = generate_end_node(cmd_line, NODE_ARGV, i[0], i[1]);
	node = head_tmp;
	return (1);
}

int	syntax_redirects(char **cmd_line, int *token, int *i, t_cmd *node)
{
	int	next_redirect_index;
	int	tmp;
	t_cmd	*head_tmp;

	head_tmp = node;
	node = generate_tree_node(NODE_REDIRECTS, -1);
	tmp = i[1];
	next_redirect_index = find_next_redirection(token, i);
	if (next_redirect_index != -1)
		i[1] = next_redirect_index - 1;
	if (syntax_simple_redirect(cmd_line, i, node->left_child) == -1)
		return (-1);
	if (next_redirect_index != -1)
	{
		i[0] = next_redirect_index;
		i[1] = tmp;
		return (syntax_redirects(cmd_line, token, i, node->right_child));
	}
	node = head_tmp;
	return (1);
}

int	syntax_simple_redirect(char **cmd_line, /*int *token,*/ int *i, t_cmd *node)
{
	t_cmd	*head_tmp;

	head_tmp = node;
	node = generate_tree_node(NODE_SIMPLE_REDIRECT, -1);
	node->left_child = generate_end_node(cmd_line, NODE_RED_TYPE,
						i[0], i[0]);
	node->right_child = generate_end_node(cmd_line, NODE_FILE_NAME,
						i[0] + 1, i[1]);
	node = head_tmp;
	return (1);
}