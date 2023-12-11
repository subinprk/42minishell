/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:34:26 by subpark           #+#    #+#             */
/*   Updated: 2023/12/11 17:56:35 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i ++]);
	free(arr);
}

void	free_stdios(t_stdio *stdios)
{
	t_stdio	*curr;
	t_stdio *next;

	curr = stdios;
	while (curr)
	{
		next = curr->next_stdio;
		free(curr);
		curr = next;
	}
}

void	free_tree(t_cmd	*tree)
{
	if (tree == NULL)
		return ;
	else
	{
		free_tree(tree->left_child);
		free_tree(tree->right_child);
		if (tree->cmdstr)
			free_2d(tree->cmdstr);
		free(tree);
	}
}