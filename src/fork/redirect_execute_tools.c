/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_execute_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:13:03 by subpark           #+#    #+#             */
/*   Updated: 2023/11/27 17:23:15 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	redirect_type(t_cmd *node)
{
	if (node->cmdstr[0] == "<")
		return (REL_TYPE_L);
	else if (node->cmdstr[0] == "<<")
		return (REL_TYPE_LL);
	else if (node->cmdstr[0] == ">")
		return (REL_TYPE_R);
	else if (node->cmdstr[0] == ">>")
		return (REL_TYPE_RR);
}

int	redirect_connect(int re_type, t_cmd *file_name)
{
	if (re_type == REL_TYPE_L)
	{

	}
	else if (re_type == REL_TYPE_LL)
	{

	}
	else if (re_type == REL_TYPE_R)
	{

	}
	else if (re_type == REL_TYPE_RR)
	{
		
	}
}