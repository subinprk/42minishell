/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:22:53 by siun              #+#    #+#             */
/*   Updated: 2023/12/05 16:28:31 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	array_length_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i ++;
	return (i);
}

int	token_length(int *token)
{
	int	i;

	i = 0;
	while (token[i] != 0)
		i ++;
	return (i);
}