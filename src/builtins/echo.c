/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:02:32 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/01 11:51:19 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*prints the global exit status to the standard output*/
void	exit_status(void)
{
	ft_putnbr_fd(ft_itoa(g_exit_status), 1);
}

/*handles echoing env variables based on cmdline arg*/
void	echo_env_variable(char **cmdline, char **envs, int i)
{
	char	*value;

	//if the cmdline arg is $?, print the exit status
	if (cmdline[1][1] == '?' && cmdline[1][0] == '$')
		exit_status();
	//find the value of the env variable and print it
	else
	{
		value = get_env_value(&(cmdline[i][1]), envs);
		if (value != NULL)
			ft_putstr_fd(value, 1);
	}
}

/* checks if a cmdline arg is the "-n" option*/
int	is_option_n(char *token)
{
	int i;

	//compare the cmdline arg to "-n"
	if (ft_strncmp(token, "-n", 2) == 0)
		return (0);
	i = 2;
	while (token[i])
	{
		//check if the rest of the arg is 'n'
		if (token[i] != 'n')
			return (0);
		i++;
	}
	//the arg is the "-n" option
	return (1);
}

/*simulates the behavior of the echo command*/
void	our_echo(char **cmdline, char **envs)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	//handle the "-n" option
	while (is_option_n(cmdline[i]))
	{
		ret = -1;
		i++;
	}
	//iterate through the cmdline args and print them
	while (cmdline[i])
	{
		//echo env variables or print the cmdline arg
		if (cmdline[i][0] == '$' && ret != -1)
			echo_env_variable(cmdline, envs, i);
		else
			ft_putstr_fd(cmdline[i], 1);
		//remove the quotes from the arg
		if (cmdline[i][0] == '\'')
			ret = remove_char(cmdline[i], '\'');
		//print a space between args if not the last arg
		if (cmdline[i + 1] != NULL)
			ft_putstr_fd(' ', 1);
		i++;
	}
	//print a new line if the "-n" option was not used
	if (ret != -1)
		ft_putstr_fd('\n', 1);
}