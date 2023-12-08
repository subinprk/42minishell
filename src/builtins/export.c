/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:34:58 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/08 16:33:01 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*prints the contents of the env array to the standard output, each element
on a new line*/
void    print_export(char **env)
{
    int i;

    i = -1;
    while (env[++i])
    {
        ft_putstr_fd(env[i], 1);
        ft_putstr_fd("\n", 1);
    }
}

/*checks if a given key(part of an enviromental variable) is valid*/
int     is_valid_export_key(char *key)
{
    int i;

    i = -1;
    while (key[++i])
    {
        if (key[i] >= '0' && key[i] <= '9')
            return (1);
    }
    return (0);
}

/*adds a new env variable str to the new array*/
void	add_export_variable(char *str, char **new, int i)
{
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
}

/* checks if tje enviromental variable str exists in the env array. If
it exists, updates the value, if not, adds a new variable.*/
int	update_or_add_export(char *str, char ***env)
{
	int i;
	char **temp;

	if (str[0] == '=' || str[0] == '\0' || ft_strlen(str) == 1)
		return (-1);
	i = -1;
	while ((*env)[++i])
	{
		if(!ft_strncmp((*env)[i], str, ft_strlen(str)))
		{
			(*env)[i] = ft_strdup(str);
			return (0);
		}
	}
	if (!(temp = (char **)malloc(sizeof(char *) * (i + 2))))
		return (-1);
	i = -1;
	while ((*env)[++i])
		temp[i] = ft_strdup((*env)[i]);
	add_export_variable(str, temp, i);
	*env = temp;
	return (0);	
}

/*THe function implement the export command*/
void    execute_export_command(t_cmd *cmd, char **cmdline)
{
    char    **temp;
    int     i;
    int     ret;

    temp = cmdline;
    i = 0;
    ret = 0;
    if (cmd == NULL)
        return ;
    if (double_char_len(cmdline) == 1)
        print_export(g_envp);
    else
    {
        remove_char(cmdline[1], '\'');
        while (cmdline[++i])
        {
            if (is_valid_export_key(strtok(temp[i], "=")))
            {
                print_id_error(cmdline[i], "export");
                g_exit_status = 1;
            }
            remove_char(cmdline[i], '$');
            ret = update_or_add_export(cmdline[i], &g_envp);
        }
    }
    if (ret != 0)
        g_exit_status = 1;
}