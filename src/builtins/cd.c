/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:59:52 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/01 11:51:13 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//changes the current working directory to the user's home directory
int	cd_to_home_directory(char *current_path, char **cmdline, char **envs)
{
	//check if the argument is "~", print an error and set the exit status
	if (cmdline[1][1] == '~')
	{
		print_error2("cd", cmdline[1], "No such file or directory");
		g_exit_status = 1;
	}
	//get the value of the HOME variable
	current_path = get_env_value("HOME", envs);
	//change the current working directory to the value of the HOME variable
	if (chdir(current_path) == -1)
		print_error("cd", "HOME not set");
	return (1);
}

//changes the current working directory to the value of the environment variable
int	cd_to_env_variable(char *current_path, char **cmdline, char **envs)
{
	//extract the enviroment variable name from the argument
	current_path = find_value(&(cmdline[1][1]), envs);
	//change the current working directory to the value of the environment variable
	//fallback to HOME directory if failed
	if (chdir(current_path) == -1)
		chdir(find_value("HOME", envs));
	return (1);
}

//updates the PWD and OLDPWD variables after successful cd
void	update_pwd_variables(char **envs)
{
	char	*current_pwd;
	char	*old_pwd;
	char	*temporary_buffer;

	//allocate memory for the temporary buffer
	temporary_buffer = malloc(sizeof(char) * 1024);
	//create strings with the new PWD and OLDPWD values
	current_pwd = ft_strjoin("PWD=", getcwd(temporary_buffer, 1024));
	old_pwd = ft_strjoin("OLDPWD=", find_value("PWD", envs));
	//update the environment variables
	check_export(current_pwd, &envs);
	check_export(old_pwd, &envs);
	free(current_pwd);
	free(old_pwd);
}

//main function for the cd builtin, handles different cases
void	change_directory(char **cmdline, char **envs)
{
	char	*current_path;
	int		result;

	current_path = 0;
	result = 0;
	//case when a specific path is provided
	if (cmdline[1] != NULL && cmdline[1][0] != '~' && cmdline[1][0] != '$')
	{
		current_path = cmdline[1];
		//change the current working directory to the specified path, print an error if failed
		if (chdir(current_path) == -1)
			result = print_error2("cd", current_path, strerror(errno));
		update_pwd_variables(envs);
	}
	//case no path is provided or the path is "~"
	else if (cmdline[1] == NULL && cmdline[1][0] == '-')
		cd_to_home_directory(current_path, cmdline, envs);
	//case the path is "$"
	else if (cmdline[1][0] == '$')
		cd_to_env_variable(current_path, cmdline, envs);
	//update the exit status based on the success or failure of the cd command
	if (result == -1)
		g_exit_status = 1;
	else
		g_exit_status = 0;
}
