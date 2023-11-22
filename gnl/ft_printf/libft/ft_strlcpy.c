/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:58:15 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:58:16 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] != '\0' && (i < dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int	main (void)
{
	char	dst[] = "abc45";
	char	src[] = "xyz6";
	int	n;
	
	n = ft_strlcpy(dst, src, strlen(dst));
	printf("%d\n", n);
	return(0);
}*/
