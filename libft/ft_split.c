/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:46:17 by subpark           #+#    #+#             */
/*   Updated: 2023/05/11 15:07:25 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	countrow(char const *s, char c)
{
	char	prvc;
	int		index;
	int		row;

	row = 0;
	index = 0;
	prvc = 0;
	if (s[index] != c && s[index] != 0)
		row ++;
	while (s[index])
	{
		if (prvc == c && s[index] != c)
			row ++;
		prvc = s[index];
		index ++;
	}
	if (c == 0)
		row = row - 1;
	return (row);
}

int	tool4free(char **str, int i4str)
{
	if (str[i4str] == NULL)
	{
		while (i4str >= 0)
			free(str[i4str --]);
		free(str);
		return (-1);
	}
	return (1);
}

char	**linebyline(char **str, char const *s, char c)
{
	int	index;
	int	i4str;
	int	start;

	index = 0;
	i4str = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			start = index;
			while (s[index] != c && s[index])
				index ++;
			str[i4str] = ft_substr(s, start, index - start);
			if (tool4free(str, i4str) < 0)
				return (NULL);
			i4str ++;
		}
		else
			index ++;
	}
	str[i4str] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		row;

	row = countrow(s, c);
	str = (char **)malloc((row + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	str = linebyline(str, s, c);
	return (str);
}
/*
#include <mcheck.h>
#include <stdio.h>
int main()
{
	int row = countrow("nonempty", 0);
	//int column = countcolumn("", ' ');
	int	i;
	char **str = ft_split("nonempty", 0);
	printf("%d\n", row);
	for(i = 0; i <= row; i++)
		printf("%d 번째 열 %s\n", i, str[i]);
	//mcheck(str[1]);
	for(i = 0; i <= row; i++)
	{
		free(str[i]);
		printf("free %d\n", i);
	}
	free(str);
	printf("final free \n");
	return 0;
}*/