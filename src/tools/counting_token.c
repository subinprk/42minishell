/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:45:22 by siun              #+#    #+#             */
/*   Updated: 2023/11/23 15:57:11 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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