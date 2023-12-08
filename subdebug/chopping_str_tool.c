/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopping_str_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:21 by subpark           #+#    #+#             */
/*   Updated: 2023/12/06 18:58:24 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
/*
void	putting_words(char **word, char *str, int start, int length)
{
	int	i;

	i = 0;
	printf("%d start %d length\n", start, length);
	while (i < length)
	{
		(*word)[i] = str[start + i];
		printf("%c", str[start + i]);
		i ++;
	}
	*(word[length]) = 0;
}
*/
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
	while (str[*i] == ' ')
	{
		printf("counting spaces   ");
		(*i) ++;
	}
	if (str[*i] != 0)
		(*count) ++;
	printf("spaces counted\n");
}

char	*strdup_rellocator(char *str, int *i)
{
	if (str[*i] == '<')
	{
		if (str[(*i) + 1] =='<')
		{	
			(*i) ++;
			return (strdup("<<"));
		}
		else
			return (strdup("<"));
	}
	else if (str[*i] == '>')
	{
		if (str[(*i) + 1] =='>')
		{	
			(*i) ++;
			return (strdup(">>"));
		}
		else
			return (strdup(">"));
	}
	return (NULL);
}

char	*strdup_word(char *str, int *i)
{
	char	*word;
	int		word_length;
	int		start;

	start = *i;
	word_length = count_word_length(str, *i);
	printf("word_length : %d\n", word_length);
	word = (char *)malloc(sizeof(char) * (word_length + 1));
	if (!word)
		return (NULL);
	while ((*i) < word_length + start)
	{
		word[(*i) - start] = str[(*i)];
		(*i) ++;
	}
	word[word_length] = 0;
	return (word);
}


int	count_line(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|' && i ++ > 0)
			count ++;
		else if (str[i] == ' ' && count > 0)
			find_spaces(str, &i, &count);
		else if (str[i] == '<' || str[i] == '>')
			find_rellocator(str, &i, &count);
		else if(str[i] == '\'' && i ++ > 0)
			count ++;
		else if (str[i] == '"' && i ++ > 0)
			count ++;
		else
			i ++;
		printf("count : %d\n", count);
	}
	if (composing_word(str[i]))
		count ++;
	return (count);
}

char	*line_by_line(char *str, int *i)
{
	char	*line;

	while (str[*i])
	{
		if (str[*i] == ' ')
			(*i) ++;
		else if (str[*i] == '\'' &&  str[(*i) ++] > -1)
			return (strdup("'"));//not sure if it is possible just send strdup directly as return value
		else if (str[*i] == '"' &&  str[(*i) ++] > -1)
			return (strdup("\""));
		else if (str[*i] == '|' &&  str[(*i) ++] > -1)
			return (strdup("|"));
		else if ((str[*i] == '<' || str[*i] == '>') &&  str[(*i) ++] > -1)
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

	chopped = (char **)malloc(sizeof(char *) * (count_line(str) + 1));
	printf("count_line result:  %d\n", count_line(str));
	if (!chopped)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i])
	{
		chopped[index] = line_by_line(str, &i);
		/*if (!chopped[index])
		{
			free_2d(chopped);
			return (NULL);
		}*/
		//i ++;
		index ++;
	}
	return (chopped);
}

int main()
{
	char **chopped;
	int	i;

	chopped = chopping_str("   hello world It's Subin    !");
	i = 0;
	while (chopped[i])
	{
		printf("line %d print: %s\n", i, chopped[i]);
		i ++;
	}
	i = 0;
	while (chopped[i])
		free(chopped[i ++]);
	free(chopped);
}