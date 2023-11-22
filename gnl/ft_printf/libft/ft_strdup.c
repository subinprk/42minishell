/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:57:43 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:57:44 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*des;

	size = 0;
	while (src[size])
		++size;
	des = malloc(sizeof(char) * (size + 1));
	if (!des)
		return (0);
	i = 0;
	while (src[i])
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
/*
int	main()
{
	char	str[] = "abcdefghilyfd";
	char	*target = ft_strdup(str);
	
	printf("%s\n", target);
	return 0;
}*/
