/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:56:35 by irivero-          #+#    #+#             */
/*   Updated: 2023/11/23 14:06:01 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*allocates memory for a string ad sets all its bytes to '\0'*/
char    *ft_strnew(size_t size)
{
    char    *str;
    size_t    i;

    i = 0;
    str = (char *)malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    while (i < size)
    {
        str[i] = '\0';
        i++;
    }
    str[i] = '\0';
    return (str);
}