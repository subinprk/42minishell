/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:24 by subpark           #+#    #+#             */
/*   Updated: 2023/12/13 05:45:22 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//redirector, pipe, will be in other lexicon

#include "../../include/minishell.h"

t_cmd	*extract_command(char *str)
{
	t_cmd	*cmd_tree;
	char	**chopped_str;
	int		*token;
	int		i[2];
	int		tmp;

	if (str == NULL || str[0] == 0)
		return (NULL);
	cmd_tree = NULL;
	chopped_str = chopping_str(str);
	if (!chopped_str)
		return (NULL);
	token = token_data(chopped_str);
	if (!token)
		return (NULL);
	//function that parsing token & generate cmd linked list
	i[0] = 0;
	i[1] = token_length(token);
	tmp = syntax_pipe(chopped_str, token, i, &cmd_tree);
	if (tmp == -1)
		//tree freeing
		return(NULL);
	free_2d(chopped_str);
	free(token);
	return (cmd_tree);
}
