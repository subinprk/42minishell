/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:33:17 by subpark           #+#    #+#             */
/*   Updated: 2023/05/10 17:25:25 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc (size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * nmemb));
	return ((void *)ptr);
}
/*
int main(){
	int *str;
	str = ft_calloc(2147483647, 2147483647);
	printf("%d", str[20]);
	free(str);
	return 0;
}*/
