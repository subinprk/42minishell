/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopping_word_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:17:44 by subpark           #+#    #+#             */
/*   Updated: 2023/12/06 14:20:54 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	composing_word(char c)
{
	if (c != ' ' && c != '|' && c != '<' && c != '>' && c != '\'' && c != '"')
		return (1);
	else
		return (0);
}

int	count_word_length(char *str, int start)
{
	int	i;

	i = 0;
	while (composing_word(str[start + i]))
		i ++;
	return (i);
}
