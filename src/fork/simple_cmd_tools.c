/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:11:50 by subpark           #+#    #+#             */
/*   Updated: 2023/12/01 15:43:24 by irivero-         ###   ########.fr       */
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

void	builtin_action(t_cmd *builtin, char **cmdline)
{
	char	*builtins;

	builtins = builtin->cmdstr[0];
	if (!ft_strcmp(builtins, "echo"))
		our_echo(cmdline, g_envp);
	else if (!ft_strcmp(builtins, "cd"))
		change_directory(cmdline, g_envp);
	else if (!ft_strcmp(builtins, "pwd"))
		our_pwd();
	else if (!ft_strcmp(builtins, "export"))
		execute_export(builtin, cmdline);
	else if (!ft_strcmp(builtins, "unset"))
		execute_unset_command(builtin, cmdline);
	else if (!ft_strcmp(builtins, "env"))
		env(g_envp);
	else if (!ft_strcmp(builtins, "exit"))
		exit_command(builtin, cmdline);
	else
		return (0);
	return (1);
}