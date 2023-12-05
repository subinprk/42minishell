/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:42:13 by subpark           #+#    #+#             */
/*   Updated: 2023/06/01 11:04:17 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			index;

	if (n == 0 || dest == src)
		return (dest);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		tmp_dest[index] = tmp_src[index];
		index ++;
	}
	return (dest);
}
