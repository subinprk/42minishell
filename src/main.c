/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:48:01 by subpark           #+#    #+#             */
/*   Updated: 2023/12/13 12:05:30 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envs)
{
//	char	**line;
	int		index;
	char	*tmp;
	char	**envp;
	t_cmd	*tree;
	int		ret;
//	line = NULL;

	(void)argv;
//subin: should be initialised as a function for norminette later
	index = 0;
	g_envp = cpy_full_2d_array(envs);
	envp = paths_array(envs);
	set_signal();
	ret = argc;
	while(ret)
	{
		//tree = extract_command(line[index]);
		generate_prompt();
		ret = get_line(&tmp);
		
		tree = extract_command(tmp);
		search_tree(tree, envp);
		index ++;
		free(tmp);
		free_tree(tree);
	}
//also freeing shoud be in different function
	free_2d(envp);
	free_2d(g_envp);
	exit(g_exit_status & 255);
}