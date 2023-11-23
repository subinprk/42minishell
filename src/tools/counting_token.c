/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:45:22 by siun              #+#    #+#             */
/*   Updated: 2023/11/23 03:54:50 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_token(int *token, int token_identifier)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (token[i] != -1)
	{
		if (token[i] == token_identifier)
			count ++;
		i ++;
	}
	return (count);
}