/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:56:18 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:56:20 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (!to && !from)
		return (0);
	ptr = (unsigned char *)to;
	ptr2 = (unsigned char *)from;
	while (n-- > 0)
		*(ptr++) = *(ptr2++);
	return (to);
}
/*
int	main(void)
{
	char	dest[] = "11223344";
	const char	src[] = "abcdefghi";
	printf("%s\n", dest);
	ft_memcpy(dest, src, strlen(src)-4);
	printf("%s\n", dest);
	return(0);
}*/
