/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:57:33 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:57:35 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char*str, int c)
{
	while (*str != (char)c && *str)
		str++;
	if ((char)c != '\0' && *str == '\0')
		return (NULL);
	return ((char *)str);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	a[] = "aabbccdeefff";
	char 	*c;
	
	c = ft_strchr(a, 'z');
	printf("%s\n", c);
	return (0);
}*/
