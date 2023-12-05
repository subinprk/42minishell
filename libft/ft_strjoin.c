/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:03:46 by subpark           #+#    #+#             */
/*   Updated: 2023/05/11 13:03:04 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[i1])
	{
		str[i1] = s1[i1];
		i1 ++;
	}
	while (s2[i2])
	{
		str[i1 + i2] = s2[i2];
		i2 ++;
	}
	str[i1 + i2] = 0;
	return (str);
}
/*
int main(){

	printf("result : %s", ft_strjoin("hello ","world"));
	return (0);
}*/
