/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:32:13 by irivero-          #+#    #+#             */
/*   Updated: 2023/11/22 18:26:16 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int to_array(t_data *data)
{
    //to do a string_count function!
    data->current_index = 0;
    data->args_index = 0;
    data->args_count = -1;
    data->quote = 0;

    if (!data->args_size[0] || data->prompt[0] == '\n' || !data->prompt[0])
    {
        free(data->prompt);
        return (0);
    }
    while (data->args_size[++data->args_count])
        ;
    data->args = ft_calloc(data->args_count + 1, sizeof(char *));
    if (!data->args)
        return (0);
    while (--data->args_count >= 0)
        data->args[data->args_count] = ft_calloc(data->args_size[data->args_count] + 1,
            sizeof(char));
    while (data->prompt[data->current_index] == ' ' || 
        data->prompt[data->current_index] == '\t')
        data->current_index++;
    while (data->prompt[data->current_index] && data->prompt[data->current_index]
            != '\n')
        //parsing function
    data->args[data->args_index][++data->args_count] = '\0';
    data->args[data->args_index + 1] = 0;
    free(data->prompt);
    return (1);
}