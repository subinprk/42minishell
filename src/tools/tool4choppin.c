/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool4choppin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:21 by subpark           #+#    #+#             */
/*   Updated: 2023/11/27 15:11:13 by subpark          ###   ########.fr       */
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
	while (str[*i])
	{
		
	}
}