/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:30:36 by irivero-          #+#    #+#             */
/*   Updated: 2023/11/22 18:27:17 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	generate_prompt(t_data *data, char **envp)
{
	var_init(data, 1, envp);
	data->d_null = open("/dev/null", O_WRONLY);
	data->prompt = readline("our shell");
	if (!data->prompt)
		exit_minishell(data);
	add_history(data->prompt);
	if(to_array(data))
		exec_minishell(data);
	free(data->args_size);
}

void	var_init(t_data *data, int argc, char **envp)
{

}

void	exec_minishell(t_data *data)
{
	
}