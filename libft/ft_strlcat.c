/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:47:31 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 15:25:36 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		t1;
	size_t		t2;

	i = 0;
	t1 = ft_strlen(dst);
	t2 = ft_strlen(src);
	if (size <= t1)
		return (size + t2);
	while (dst[i] && i < size - 1)
		i ++;
	while (src[i - t1] && i < size - 1)
	{
		dst[i] = src[i - t1];
		i ++;
	}
	dst[i] = 0;
	return (t1 + t2);
}
/*
#include <stdio.h>

int main()
{
	char *strb[20] = "Why?"
	char *str = ft_strlcat(strb, "why", 7);
	printf("%s", 
	return 0;
}*/
/*function that try to add 'size' bytes of src to the dst
If dst is shorter than the targeted string(part of src),
just do it till it works. But it should be ended with null byte.
return expected size of appending.*/
