/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:48:01 by subpark           #+#    #+#             */
/*   Updated: 2023/12/04 20:19:29 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envs)
{
	char	**line;
	int		index;
	t_cmd	*tree;

	line = NULL;
	index = 0;
	g_envp = cpy_full_2d_array(envs);
	set_signal();
	while(1)
	{
		get_line(line);
		tree = extract_command(line[index]);
		search_tree(tree, paths_array(envs));
		index ++;
	}
	exit(g_exit_status);
}