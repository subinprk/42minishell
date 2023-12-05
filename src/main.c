/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:48:01 by subpark           #+#    #+#             */
/*   Updated: 2023/12/05 14:17:48 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main()
{
	char	**line;
	int		index;
	t_cmd	*tree;

	line = NULL;
	index = 0;
	g_envp = ft_split(getenv("envs"), '\n');
	set_signal();
	while(1)
	{
		get_line(line);
		tree = extract_command(line[index]);
		search_tree(tree, paths_array(g_envp));
		index ++;
	}
	exit(g_exit_status);
}