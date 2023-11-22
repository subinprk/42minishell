/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:57:53 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:57:54 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void print_lowercase(unsigned int i, char *c)
{
    printf("%u %c\n", i, *c);
}

int main(void)
{
    char *str = "aabbccdd";
    ft_striteri(str, print_lowercase);
    printf("\n");
    return 0;
}*/
