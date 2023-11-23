/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:24 by subpark           #+#    #+#             */
/*   Updated: 2023/11/23 03:37:39 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//redirector, pipe, will be in other lexicon

#include "../../include/minishell.h"

t_data	*extract_command(char *str)
{
	t_data	*cmd_data;
	char	**chopped_str;
	int		*token;

	cmd_data = NULL;
	chopped_str = ft_split(str, ' ');
	if (!chopped_str)
		return (NULL);
	token = token_data(chopped_str);
	if (!token)
		return (NULL);
	free_2d(chopped_str);
	free(token);
	return (cmd_data);
}

/*
Subin's plan:

One line of command can be consisted with multiple tiny command.
So, extract_command function is from original string,
and return head of commands' linked list.
From string chopped by space,
check every single world to check it 

*/