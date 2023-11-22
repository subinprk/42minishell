/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:56:39 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:56:41 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*i;

	i = s;
	while (n-- > 0)
		*(char *)s++ = (unsigned char)c;
	return (i);
}
/*
int	main (void)
{
	char str[] = "aaaaabbbbbcccccddddddeeeee";

	ft_memset(str, '1', 5);
	printf("%s\n", str);
	return (0);
}*/
