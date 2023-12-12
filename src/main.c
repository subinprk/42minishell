/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:48:01 by subpark           #+#    #+#             */
/*   Updated: 2023/12/12 14:56:09 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envs)
{
//	char	**line;
	int		index;
	char	*tmp;
	t_cmd	*tree;

//	line = NULL;
	index = 0;
	g_envp = cpy_full_2d_array(envs);
	set_signal();
	while(argc && argv[0] != NULL)
	{
		//get_line(line);
		//tree = extract_command(line[index]);
		generate_prompt();
		tmp = readline(" ");
		size_t len = ft_strlen(tmp);
		if (len > 0 && tmp[len - 1] == '\n')
			tmp[len - 1] = '\0';
		tree = extract_command(tmp);
		search_tree(tree, paths_array(envs));
		index ++;
		free(tmp);
		free_tree(tree);
	}
	free_2d(g_envp);
	exit(g_exit_status & 255);
}