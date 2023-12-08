/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:12:42 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/08 16:11:27 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* checks if a given str is a valid env name*/
int is_valid_env_variable_name (char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (ft_isalnum(str[i]) || str[i] == '_')
            ;
        else
            return (0);
    }
    if (i == 0)
        return (0);
    return (1);
}

/* checks if a key mathces the beginning of an env var entry */
int	check_env_variable(char *key, char *env)
{
	int i;

	i = 0;
	while (key[i] && env[i] && (key[i] == env[i]) && (env[i] != '='))
		i++;
	if (key[i] == '\0' && env[i] == '=')
		return (1);
	return (0);
}

/*removes an env var by replacing it with the last one in the array*/
int unset_enviroment_variable(char *key, char ***env)
{
	int last;
	int i;

	last = 0;
	while (((*env)[last] != NULL))
		last++;
	if (last < 1)
		return (0);
	i = -1;
	while ((*env)[++i] != NULL)
	{
		if (check_env_variable(key, (*env)[i]))
		{
			free((*env)[i]);
			(*env)[i] = ft_strdup((*env)[last - 1]);
			free((*env)[last - 1]);
			(*env)[last - 1] = NULL;
			return (1);
		}
	}
	return (0);
}

/* executes the unset command, removing specified enviroment variables*/
void    execute_unset_command(t_cmd *cmd, char **cmdline)
{
    int i;
    int result;

	if (cmd = NULL)
		return ;
    i = 0;
    result = 0;
    while (cmdline[++i])
    {
        remove_char(cmdline[i], '\'');
        result = is_valid_env_variable_name(cmdline[i]) && unset_enviroment_variable(cmdline[i], &g_envp);
    }
    if (result != 1)
        g_exit_status = 1;        
}