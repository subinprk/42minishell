/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:24 by subpark           #+#    #+#             */
/*   Updated: 2023/11/23 02:35:07 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//redirector, pipe, will be in other lexicon

#include "../../include/minishell.h"

void	check_built_in_command(char	**chopped_str, int *i, t_data *cmd_head)
{
	
}

void	check_redirection(char	**chopped_str, int *i, t_data *cmd_head)
{
	//if something is redirection
	//add end node of t_data linkedlist(cmd_head)
	//Subin: I think it access function(or sth else) can be used to check
	//wheather it is file or not
	
	return ;
}

t_data	*lexicon_list_gen(char **chopped_str, int *i, t_data *cmd_head)
{
	if(!(*chopped_str))
		return (NULL);
	//check_file_dir();_not sure about specific functions. just examples
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

One line of command can be consisted with multiple tiny command.
So, extract_command function is from original string,
and return head of commands' linked list.
From string chopped by space,
check every single world to check it 

lexicon_list_gen function going to devide 
*/