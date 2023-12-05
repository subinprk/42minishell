/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:43 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 15:48:06 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (*s == '\0' && (char)c != '\0')
		return (NULL);
	return ((char *)s);
}
/*
#include <stdio.h>
int main(){
	char *str = "Hello World!";
	printf("%p ", ft_strchr(str, 'o'));
	printf("%p", ft_strchr(str, 'O'));
	return 0;
}*/
/*Function that return the pointer of the first 'c' appearing*/
