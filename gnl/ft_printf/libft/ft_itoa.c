/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:54:13 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/10 14:26:13 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nbrlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	void	ft_putnbr_write(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_putnbr_write(n / 10, str, i);
		ft_putnbr_write(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (ft_nbrlen(nbr) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr *= -1;
	}
	ft_putnbr_write(nbr, str, &i);
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	c;
	
	a = -45;
	b = -2147483648;
	c = 2147483647;
	printf("%s\n", ft_itoa(a));
	printf("%s\n", ft_itoa(b));
	printf("%s\n", ft_itoa(c));
	return (0);
}*/
