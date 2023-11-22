/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:59:24 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:59:25 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>*/
/*
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size_src;
	size_t	a;

	if (!dst || !src)
		return (0);
	size_src = ft_strlen(src);
	a = 0;
	if (dstsize != 0)
	{
		while (src[a] != '\0' && a < (dstsize -1))
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (size_src);
}	
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
		len = 0;
	if (start == ft_strlen(s) - 1 && len)
		len = 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < ft_strlen(s))
		ft_strlcpy(str, s + start, len + 1);
	else
		*str = '\0';
	return (str);
}
/*
int	main (void)
{
	char	str[] = "125676767683";
	char	*n;

	n = ft_substr(str, 2, 3);
	printf("%s\n", n);
	printf("%c\n", *n);
	return (0);
}*/
