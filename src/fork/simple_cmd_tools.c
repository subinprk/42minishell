/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:11:50 by subpark           #+#    #+#             */
/*   Updated: 2023/12/05 15:39:06 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_error_cmd(t_cmd *file_path, char **envp)
{
	char	*path_buf;

	path_buf = path_pointer(envp, file_path->cmdstr[0]);
	if (!path_buf)
	{
		printf("%s: ", file_path->cmdstr[0]);
		if (errno != 2)
			perror("");
		else
			printf("command not found\n");
	}
	free(path_buf);
	return ;
}

int	check_builtin(t_cmd *file_path)
{
	char	*builtins;

	builtins = file_path->cmdstr[0];
	if (!ft_strcmp(builtins, "echo") || !ft_strcmp(builtins, "cd")
		|| !ft_strcmp(builtins, "pwd") || !ft_strcmp(builtins, "export")
		|| !ft_strcmp(builtins, "unset") || !ft_strcmp(builtins, "env")
		|| !ft_strcmp(builtins, "exit"))
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
		execute_export_command(builtin, cmdline);
	else if (!ft_strcmp(builtins, "unset"))
		execute_unset_command(builtin, cmdline);
	else if (!ft_strcmp(builtins, "env"))
		ft_env(g_envp);
	else if (!ft_strcmp(builtins, "exit"))
		exit_command(builtin, cmdline);
}