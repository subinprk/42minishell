/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopping_str_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:21 by subpark           #+#    #+#             */
/*   Updated: 2023/11/27 15:35:12 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	find_rellocator(char *str, int *i, int *count)
{
	if (str[*i] == '<')
	{
		if (str[(*i) + 1] == '<')
			(*i) ++;
		(*count) ++;
	}
	else if (str[*i] == '>')
	{
		if (str[(*i) + 1] == '>')
			(*i) ++;
		(*count) ++;
	}
}

void	find_spaces(char *str, int *i, int *count)
{
	if (str[*i] == ' ')
	while (str[*i] == ' ')
		(*i) ++;
	(*count) ++;
}

char	*strdup_rellocator(char *str, int *i)
{
	if (str[*i] == '<')
	{
		if (str[(*i) + 1] =='<')
		{	
			(*i) ++;
			return (ft_strdup("<<"));
		}
		else
			return (ft_strdup("<"));
	}
	else if (str[*i] == '>')
	{
		if (str[(*i) + 1] =='>')
		{	
			(*i) ++;
			return (ft_strdup(">>"));
		}
		else
			return (ft_strdup(">"));
	}
}

char	*strdup_word(char *str, int *i)
{
	char	*word;
	int		word_length;

	word_length = count_word_length(str, *i);
	word = (char *)malloc(sizeof(char) * (word_length + 1));
	putting_words(&word, str, *i, word_length);
	return (word);
}