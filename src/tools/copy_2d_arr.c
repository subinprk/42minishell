/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2d_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:32:20 by siun              #+#    #+#             */
/*   Updated: 2023/11/25 17:45:19 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**text_array_part_cpy(char **line, int start, int end)
{
	int		i;
	char	**part;

	part = (char **)malloc((sizeof(char *)) * (end - start + 1));
	i = 0;
	while (i < end - start)
	{
		ft_strlcpy(part[i], line[start + i], ft_strlen(line[start + i]));
		if (!part[i])
			exit(errno);
		i ++;
	}
	part[i] = NULL;
	return (part);
}