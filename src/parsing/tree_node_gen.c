/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_node_gen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:52:28 by siun              #+#    #+#             */
/*   Updated: 2023/11/27 13:24:06 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*generate_tree_node(int node_type)
{
	t_cmd *new_node;

	new_node = (t_cmd *)malloc(sizeof(t_cmd));
	new_node->node_type = node_type;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	new_node->cmdstr = NULL;
}

t_cmd	*generate_end_node(char **line, int node_type, int start, int end)
{
	t_cmd *new_node;

	new_node = (t_cmd *)malloc(sizeof(t_cmd));
	new_node->node_type = node_type;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	new_node->cmdstr = text_array_part_cpy(line, start, end);
}
