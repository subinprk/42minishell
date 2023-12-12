/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopping_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:32:03 by subpark           #+#    #+#             */
/*   Updated: 2023/12/12 11:33:28 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_line(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '|' || str[i] == '\'' || str[i] == '"'))
		{
			count ++;
			i ++;
		}
		else if (str[i] == ' ')
			i ++;
		else if (str[i] == '>' || str[i] == '<')
		{
			count ++;
			i ++;
			if (str[i - 1] == str[i])
				i ++;
		}
		else if (((str[i] > '!' && str[i] <= '~')) && !composing_word(str[i]))
		{
			count ++;
			i ++;
		}
		else
			i ++;
	}
	return (count);
}

char	*line_by_line(char *str, int *i)
{
	char	*line;

	while (str[*i])
	{
		if (str[*i] == ' ')
			(*i) ++;
		else if (str[*i] == '\'')
		{
			(*i) ++;
			return (ft_strdup("'"));
		}
		else if (str[*i] == '"')
		{
			(*i) ++;
			return (ft_strdup("\""));
		}
		else if (str[*i] == '|')
		{
			(*i) ++;
			return (ft_strdup("|"));
		}
		else if ((str[*i] == '<' || str[*i] == '>'))
		{
			line = strdup_rellocator(str, i);
			return (line);
		}
		else
		{
			line = strdup_word(str, i);
			return (line);
		}
	}
	return (NULL);
}

char	**chopping_str(char *str)
{
	char	**chopped;
	int		i;
	int		index;
	int		num_lines;

	num_lines = count_line(str);
	chopped = (char **)malloc(sizeof(char *) * (num_lines + 1));
	if (!chopped)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i])
	{
		if (index >= num_lines)
			return (NULL);
		chopped[index] = line_by_line(str, &i);
		if (!chopped[index])
		{
			free_2d(chopped);
			return (NULL);
		}
		index ++;
	}
	chopped[num_lines] = NULL;
	return (chopped);
}