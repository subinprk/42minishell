/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:14:48 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/01 14:48:07 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int        remove_char(char *str, char c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] != c)
            str[j++] = str[i];
        i++;
    }
    str[j] = 0;
    return (1);
}

int        double_char_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int        is_stringdigit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}