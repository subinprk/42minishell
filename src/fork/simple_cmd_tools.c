/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:11:50 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 21:12:44 by subpark          ###   ########.fr       */
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

int	check_builtin(t_cmd *file_path)
{
	if (file_path->cmdstr[0] == "echo" || file_path->cmdstr[0] == "cd"
		|| file_path->cmdstr[0] == "pwd" || file_path->cmdstr[0] == "export"
		|| file_path->cmdstr[0] == "unset" || file_path->cmdstr[0] == "env"
		|| file_path->cmdstr[0] == "exit")
		return (1);
	else
		return (0);
}