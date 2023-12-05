/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2d_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:32:20 by siun              #+#    #+#             */
/*   Updated: 2023/12/05 16:38:30 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**cpy_full_2d_array(char **origin)
{
	int		i;
	int		origin_length;
	char	**array;

	array = NULL;
	origin_length = array_length_2d(origin);
	array = (char **)malloc(sizeof(char *) * ((origin_length) + 1));
	if (!array)
		exit(errno);
	i = 0;
	while(i < origin_length)
	{
		array[i] = ft_strdup(origin[i]);
		if (!array[i])
			exit(errno);
		i ++;
	}
	array[origin_length] = NULL;
	return (array);
}

char	**append_2d_array(char **origin, char *line)
{
	int		i;
	int		array_length;
	char	**tmp;

	array_length = array_length_2d(origin);
	tmp = cpy_full_2d_array(origin);
	free_2d(origin);
	origin = (char **)malloc(sizeof(char *) * (array_length + 2));
	i = 0;
	while (i < array_length)
	{
		origin[i] = ft_strdup(tmp[i]);
		i ++;
	}
	origin[array_length] = ft_strdup(line);
	origin[array_length + 1] = NULL;
	return (origin);
}

char	**text_array_part_cpy(char **line, int start, int end)
{
	int		i;
	char	**part;

	part = (char **)malloc((sizeof(char *)) * (end - start + 1));
	if (!part)
		exit(errno);
	i = 0;
	while (i < end - start)
	{
		part[i] = ft_strdup(line[start + i]);
		if (!part[i])
			exit(errno);
		i ++;
	}
	part[i] = NULL;
	return (part);
}