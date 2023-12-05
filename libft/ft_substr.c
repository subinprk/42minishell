/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:48:44 by subpark           #+#    #+#             */
/*   Updated: 2023/06/01 11:05:20 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	stringl;

	stringl = ft_strlen(s);
	if (len > stringl - start)
		len = stringl - start;
	if (stringl < start)
		return (ft_strdup(""));
	index = 0;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[index + start] != 0 && index < len)
	{
		str[index] = s[index + start];
		index ++;
	}
	str[index] = 0;
	return (str);
}
/*
#include <stdio.h>
int main(){
	char *str;

	str = ft_substr("Universe",100, 1);
	printf("result : %s", str);
	free(str);
	return (0);
}*/
