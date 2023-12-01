/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:59:47 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/01 11:51:28 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    exit_err(void)
{
	ft_putstr_fd("exit\n", 1);
	exit(g_exit_status);
}

void    exit1(t_cmd *cmd, char **cmdline)
{
    
}