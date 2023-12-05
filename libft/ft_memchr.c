/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:04 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 16:23:41 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
			return (((void *) s + index));
		index ++;
	}
	return (NULL);
}
/*Function that return the pointer appears 'c' in s
difference btw memchr and strchr
memchr designate the length of the array to find
but strchr do it till the array meet the eof*/
