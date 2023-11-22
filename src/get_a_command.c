/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:24 by subpark           #+#    #+#             */
/*   Updated: 2023/11/22 20:20:31 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//redirector, pipe, will be in other lexicon

#include "../include/minishell.h"

t_data	*lexicon_list_gen(char **chopped_str, int *i, t_data *cmd_head)
{
	if(!(*chopped_str))
		return (NULL);
	//check_file_dir();
	//check_built_in_command();
	//check_redirection();
}

t_data	*extract_command(char *str)
{
	t_data	*cmd_data;
	char	**chopped_str;
	int		i;

	cmd_data = NULL;
	chopped_str = ft_split(str, ' ');
	if (!chopped_str)
		return (NULL);
	i = 0;
	while (chopped_str[i])
	{
		lexicon_list_gen(chopped_str, &i, cmd_data);
		i ++;
	}
	free_2d(chopped_str);
	return (cmd_data);
}

/*
Subin's plan:

One line of command can be consisted of multiple tiny command.
So, extract_command function is from original string,
and return linked list of commands.
From string chopped by space,
check every single world to check it 

lexicon_list_gen function going to devide 
*/