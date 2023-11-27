/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_existence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:00:00 by siun              #+#    #+#             */
/*   Updated: 2023/11/25 18:04:38 by siun             ###   ########.fr       */
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