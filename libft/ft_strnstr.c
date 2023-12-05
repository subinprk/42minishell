/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:32 by subpark           #+#    #+#             */
/*   Updated: 2023/06/01 11:05:14 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*small == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i + j] == small[j])
		{
			while (big[i + j] && small[j])
			{
				if (big[i + j] != small[j] || i + j >= len)
					break ;
				j++;
			}
			if (small[j] == '\0')
				return (((char *)&big[i]));
		}
		i++;
	}
	return (NULL);
}
/*find and return the pointer that appear the first little*/
