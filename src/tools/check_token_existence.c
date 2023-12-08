/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_existence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:00:00 by siun              #+#    #+#             */
/*   Updated: 2023/12/08 17:38:03 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	find_existence(int *token, int target, int *i)
{
	int	count;

	count = i[0];
	while (count < i[1])
	{
		if (token[count] == target)
			return (count);
		count ++;
	}
	return (-1);
}

int	find_pipe(int *token, int *i)
{
	return (find_existence(token, TOK_PIPE, i));
}

int	find_redirection(int *token, int *i)
{
	return (find_existence(token, TOK_REDIRET, i));
}

int	find_next_redirection(int *token, int *i)
{
	int	index[2];

	index[0] = i[0] + 1;
	index[1] = i[1];
	return (find_existence(token, TOK_REDIRET, index));
}

int	how_many_token_id(int *token, int token_identifier)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (token[i] != TOK_NULL_HANDLE)
	{
		if (token[i] == token_identifier)
			count ++;
		i ++;
	}
	return (count);
}