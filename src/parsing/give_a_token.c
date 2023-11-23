/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_a_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:36:57 by siun              #+#    #+#             */
/*   Updated: 2023/11/23 03:36:31 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#define TOK_PIPE 0
#define TOK_RELLOCATE 1
#define TOK_CMD_MAIN 2
#define TOK_CMD_FLAG 3
#define TOK_S_QUOTE 4
#define TOK_D_QUOTE 5
#define TOK_D_FILE 6
#define TOK_NULL_HANDLE -1

int	is_it_same(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (!str1[i] || !str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i ++;
	}
	return (1);

}

int	is_it_rellocater(char *str)
{
	if (is_it_same(str, "<"))
		return (1);
	else if (is_it_same(str, ">"))
		return (1);
	else if (is_it_same(str, ">>"))
		return (1);
	else if (is_it_same(str, "<<"))
		return (1);
	else
		return (0);
}

int	is_it_cmd_main(char *str)
{

}

int	allocate_token(char *str)
{
	if (is_it_same(str, "|"))
		return (TOK_PIPE);
	else if (is_it_rellocater(str))
		return (TOK_RELLOCATE);
	else if (is_it_cmd_main(str))
		return (TOK_CMD_MAIN);
	else if (str[0] == '-')
		return (TOK_CMD_FLAG);
	//else if (is_it_same(str, )) not sure about the case quotation mark adjacent with other lexicon
}

int	*token_data(char **chopped_str)
{
	int	*token;
	int	token_num;
	int	i;

	token_num = array_length_2d(chopped_str);
	token = (int *)malloc(sizeof(int) * (token_num + 1));
	i = 0;
	while (i < token_num)
	{
		token[i] = allocate_token(chopped_str[i]);
		i ++;
	}
	token[token_num] = TOK_NULL_HANDLE;
	return (token);
}