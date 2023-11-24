/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:40:29 by siun              #+#    #+#             */
/*   Updated: 2023/11/24 16:24:52 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
t_data	*parse_tokens(t_data *cmd_data, char **chopped_str, int *token)
{
	//if ()
	//quote, dquote error handling, if it's number is odd, also read next line
}*/

void	syntax_pipe(char **cmd_part, int *token, int i)
{
	syntax_cmds();
	if (/*there is more pipe*/)
		syntax_pipe(cmd_part, token, /*next pipe index*/);
}

void	syntax_cmds(char **cmd_part, int *token, int i)
{
	syntax_simple_cmd();
	if (/*there is redirections*/)
		syntax_redirects(cmd_part, token, /*redirection index*/);
}

void	syntax_simple_cmd()
{

}

void	syntax_redirects()
{
	syntax_simple_redirect();
	if (/*there is more redirects*/)
		syntax_redirects(cmd_part, token, /*next redirection index*/);
}

void	syntax_simple_redirect()
{
	

}