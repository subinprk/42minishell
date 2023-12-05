/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:20 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 13:44:35 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (index < size - 1 && src[index] != 0)
	{
		dst[index] = src[index];
		index ++;
	}
	dst[index] = 0;
	return (ft_strlen(src));
}
