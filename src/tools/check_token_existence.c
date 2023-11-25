/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_existence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:00:00 by siun              #+#    #+#             */
/*   Updated: 2023/11/25 14:24:04 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	find_existence(int *token, int target, int i)
{
	while (token[i] != TOK_NULL_HANDLE)
	{
		if (token[i] == target)
			return (i);
		i ++;
	}
	return (-1);
}

int	find_pipe(int *token, int i)
{
	return (find_existence(token, TOK_PIPE, i));
}

int	find_redirection(int *token, int i)
{
	return (find_existence(token, TOK_REDIRET, i));
}