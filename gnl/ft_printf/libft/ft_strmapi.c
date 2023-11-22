/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:58:28 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:58:30 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
char    ft_upper(unsigned int i, char c)
{
    if (i < 10000000)
    {
        if (c >= 'a' && c <= 'z')
            c = c - 32;
    }
    return (c);
}

int main()
{
    char *s = "hello";
    char *mapped = ft_strmapi(s, &ft_upper);
    printf("%s\n", mapped); // Prints "HELLO"
    free(mapped);
}*/
