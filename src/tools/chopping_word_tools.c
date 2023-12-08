/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopping_word_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:17:44 by subpark           #+#    #+#             */
/*   Updated: 2023/12/07 17:37:12 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	composing_word(char c)
{
	if (c != ' ' && c != '|' && c != '<' && c != '>' && c != '\''
		&& c != '"' && c != ' ' && c != '\0')
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
