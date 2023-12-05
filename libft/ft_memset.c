/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:20:18 by subpark           #+#    #+#             */
/*   Updated: 2023/06/01 12:51:17 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	index;
	unsigned char	*str;

	str = s;
	index = 0;
	while (index < n)
	{
		*(str + index) = c;
		index ++;
	}
	return (s);
}
