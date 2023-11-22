/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:27:26 by irivero-          #+#    #+#             */
/*   Updated: 2023/11/22 17:39:57 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exit_correct(t_data *data)
{
	if (data->args_tmp[1] && !ft_isdigit((data->args_tmp[1][0])))
	{
		printf("exit: numbers required\n");
		data->error = 255;
	}
	else if (data->args_tmp[1] && !data->args_tmp[2])
		exit(ft_atoi(data->args_tmp[1]) % 256);
	exit(data->error);
}

void    exit_minishell(t_data *data)
{
    int		i;
	char	*message;

	message = "bye bye";
	if (data->prompt && !data->args_tmp[2])
	{
		i = -1;
		while (data->args[++i])
			free(data->args[i]);
		free(data->args);
		free(data->args_size);
	}
	write(1, message, ft_strlen(message));
	if (!data->prompt)
		exit(data->error);
	else if (data->args_tmp[1] && data->args_tmp[2] \
			&& ft_isdigit(data->args_tmp[1][0]))
	{
		printf("exit: too many arguments\n");
		data->error = 1;
	}
	else
		exit_correct(data);
}