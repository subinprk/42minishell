/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:59:27 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 16:04:31 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_error_cmd(t_cmd *file_path, char **envp)
{
	char	*path_buf;

	path_buf = path_pointer(envp, file_path->cmdstr[0]);
	if (!path_buf)
	{
		ft_printf("%s: ", file_path->cmdstr[0]);
		if (errno != 2)
			perror("");
		else
			ft_printf("command not found\n");
	}
	free(path_buf);
	return ;
}