/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:56:01 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:56:03 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*
int	main (void)
{
	const char	s[] = "af.234567";
	const char	i = '.';
	char	*ret;
	
	ret = ft_memchr(s, i, 2);
	printf ("%c %s\n", i, ret);
	return (0);
}*/
