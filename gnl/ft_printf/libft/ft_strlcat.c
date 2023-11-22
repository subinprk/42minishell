/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:58:05 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:58:07 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	m;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	n = ft_strlen(dst);
	m = 0;
	while (src[m] != 0 && n + 1 < size)
	{
		dst[n] = src[m];
		n++;
		m++;
	}
	dst[n] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[m]));
}
/*
#include <stdio.h>
int	main(void)
{
	char	a[] = "ab";
	char	b[] = "rst";
	int	c;
	
	c = ft_strlcat(a, b, 8);
	printf("%d\n", c);
	return(0);
}*/