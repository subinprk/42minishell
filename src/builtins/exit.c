/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:59:47 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/01 14:56:00 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    exit_err(void)
{
	ft_putstr_fd("exit\n", 1);
	exit(g_exit_status);
}

void    exit_command(t_cmd *cmd, char **cmdline)
{
	int ac;

	ac = 0;
    if (cmd->pre_flag == 1) 
		return ;
	while (cmdline[ac] != NULL) //counts the number of arguments
		ac++;
	if (ac == 1)
		exit_err(); //if ac is 1 just exit
	if (ac == 2 && is_stringdigit(cmdline[1])) // if ac is 2 and the second argument is a number, it stores in g_exit status
		g_exit_status = ft_atoi(cmdline[1]);
	if (ac > 2 && is_stringdigit(cmdline[1])) // deals if there are too many ac
	{
		ft_putstr_fd("exit\n", 1);
		print_error("exit", "too many arguments");
		g_exit_status = 1;
	}
	else // deals if the second argument is not a number
	{
		print_error2("exit", cmdline[1], "numeric argument required");
		// if it reaches this part it means that an error happened, and the exit status is set to 255
		// the code 255 its truncated to 8 bits using & 255
		g_exit_status = 255;
		exit(g_exit_status && 255);
	}
	exit_err();
}