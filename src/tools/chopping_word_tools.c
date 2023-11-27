/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopping_word_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:17:44 by subpark           #+#    #+#             */
/*   Updated: 2023/11/27 15:35:05 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	composing_word(char c)
{
	if (c != ' ' & c != '|' & c != '<' & c != '>' & c != '\'' & c != '"')
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

void	putting_words(char **word, char *str, int start, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		*word[i] = str[start + i];
		i ++;
	}
	*word[length] = NULL;
}