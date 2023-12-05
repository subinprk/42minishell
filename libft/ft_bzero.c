/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:57:35 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 12:59:41 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			index;

	str = s;
	index = 0;
	while (index < n)
	{
		*(str + index) = 0;
		index ++;
	}
	return ;
}
