/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:32:13 by irivero-          #+#    #+#             */
/*   Updated: 2023/11/23 14:06:49 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* determine if a given string, consistes of whitespace characters*/
int        is_whitespace(char *c)
{
    int        i;
    int        space;

    if(c[0] == 0)
        return (1);
    while (c[i])
    {
        if (c[i] == '\r' || c[i] == '\v' || c[i] == '\t' || c[i] == '\f')
            return (1);
        else if (c[i] == ' ')
            space++;
        i++;
    }
    if (space == (int)ft_strlen(c))
        return (1);
    return (0);
}

void    *parse(char *input)
{
    
}