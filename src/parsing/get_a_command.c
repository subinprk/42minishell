/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:24 by subpark           #+#    #+#             */
/*   Updated: 2023/12/08 13:45:07 by subpark          ###   ########.fr       */
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

	//int		t;

	cmd_tree = NULL;
	chopped_str = chopping_str(str);
	if (!chopped_str)
		return (NULL);
	token = token_data(chopped_str);
	if (!token)
		return (NULL);
	/*t = 0;
	while (token[t])
	{
		printf("token: %d\n", token[t]);
		t ++;
	}*/
	//function that parsing token & generate cmd linked list
	i[0] = 0;
	i[1] = token_length(token);
	syntax_pipe(chopped_str, token, i, cmd_tree);
//	printf("is tree null ? : %p", &cmd_tree);
	free_2d(chopped_str);
	free(token);
	return (cmd_tree);
}
