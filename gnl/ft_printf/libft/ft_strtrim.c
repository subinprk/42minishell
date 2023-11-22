/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:59:15 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:59:17 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_setcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}
/*
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size_src;
	size_t	a;

	if (!dst || !src)
		return (0);
	size_src = ft_strlen(src);
	a = 0;
	if (dstsize != 0)
	{
		while (src[a] != '\0' && a < (dstsize -1))
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (size_src);
}	

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (0);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_setcheck(s1[start], set))
		start++;
	while (end > start && ft_setcheck(s1 [end -1], set))
		end --;
	str = ((char *)malloc(sizeof(char) * (end - start + 1)));
	if (!str)
		return (0);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	str1[] = "abcdefgcc";
	char	str2[] = "gcc";
	char	str3[] = "ab";
	char	str4[] = "de";

	printf("%s\n", ft_strtrim(str1, str2));
	printf("%s\n", ft_strtrim(str1, str3));
	printf("%s\n", ft_strtrim(str1, str4));
	return (0);
}*/
