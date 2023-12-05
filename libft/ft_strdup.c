/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:25:45 by subpark           #+#    #+#             */
/*   Updated: 2023/05/10 17:47:59 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		index;

	index = 0;
	str = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[index] != 0)
	{
		str[index] = s[index];
		index ++;
	}
	str[index] = 0;
	return (str);
}
/*function that make the copy string of the given string*/
