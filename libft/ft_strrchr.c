/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:48:16 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 15:56:45 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen(s);
	while (index >= 0 && s[index] != (char)c)
		index --;
	if (s[index] == (char)c)
		return ((char *)(s + index));
	return (0);
}
/*function that find the last appearance of c*/
