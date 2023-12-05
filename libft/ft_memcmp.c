/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:26:33 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 16:39:26 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				index;

	str1 = s1;
	str2 = s2;
	index = 0;
	while (index < n)
	{
		if (*(str1 + index) == *(str2 + index))
			index ++;
		else
			return (str1[index] - str2[index]);
	}
	return (0);
}
