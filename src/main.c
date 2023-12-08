/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:48:01 by subpark           #+#    #+#             */
/*   Updated: 2023/12/08 15:15:29 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envs)
{
//	char	**line;
	int		index;
	char	*tmp;
	t_cmd	*tree;

	/*index = 0;
	while (envs[index])
	{
		printf("line %d content: %s\n", index, envs[index]);
		index ++;
	}*/
//	line = NULL;
	index = 0;
	g_envp = cpy_full_2d_array(envs);
	set_signal();
	while(argc && argv[0] != NULL)
	{
		//get_line(line);
		//tree = extract_command(line[index]);
		generate_prompt();
		tmp = readline("");
		tree = extract_command(tmp);
		//print_every_node(tree, 0);
		//search_tree(tree, paths_array(envs));
		index ++;
		//free_tree(tree);
	}
	free_2d(g_envp);
	exit(g_exit_status);
}