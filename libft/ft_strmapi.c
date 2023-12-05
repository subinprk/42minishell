/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:11:05 by subpark           #+#    #+#             */
/*   Updated: 2023/05/15 18:16:00 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str || !f)
		return (0);
	index = 0;
	while (s[index] != 0)
	{
		str[index] = f(index, s[index]);
		index ++;
	}
	str[index] = 0;
	return (str);
}
