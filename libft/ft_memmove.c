/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:32:54 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 12:41:07 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			index;

	index = 0;
	if (n == 0 || dest == src)
		return (dest);
	if (src >= dest)
	{
		tmp_dest = dest;
		tmp_src = (unsigned char *)src;
		while (index < n)
		{
			tmp_dest[index] = tmp_src[index];
			index ++;
		}
	}
	else
	{
		tmp_dest = dest + n - 1;
		tmp_src = (unsigned char *)src + n - 1;
		while (n --)
			*tmp_dest -- = *tmp_src --;
	}
	return (dest);
}
