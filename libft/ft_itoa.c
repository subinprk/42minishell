/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:13:30 by subpark           #+#    #+#             */
/*   Updated: 2023/05/11 16:38:19 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

#include <stdlib.h>
#include "libft.h"

int	tool4size(int n, int count)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		return (tool4size(-n, count + 1));
	else if (n < 10 && n > 0)
		return (count);
	else if (n == 0)
		return (count);
	else
		return (tool4size(n / 10, count + 1));
}

void	fillstring(char *str, int n, int length)
{
	int	index;

	index = 0;
	while (n > 0)
	{
		str[length - index - 1] = n % 10 + '0';
		n = n / 10;
		index++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = tool4size(n, 1);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, length + 1);
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	else if (n < 0)
	{
		str[0] = '-';
		n = (-1) * n;
	}
	else if (n == 0)
		str[0] = '0';
	fillstring(str, n, length);
	return (str);
}
/*
void main()
{
	char	*str;
	printf("%d\n", tool4size(0, 0));
	str = ft_itoa(-567);
	printf("%s", str);
	free(str);
}
*/