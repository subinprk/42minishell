/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:40:29 by siun              #+#    #+#             */
/*   Updated: 2023/11/25 14:24:01 by siun             ###   ########.fr       */
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
	int	pipe_index;

	syntax_cmds(cmd_part, token, i);
	pipe_index = find_pipe(token, i);
	if (pipe_index != -1)
		syntax_pipe(cmd_part, token, pipe_index);
}

void	syntax_cmds(char **cmd_part, int *token, int i)
{
	int	redirect_index;

	syntax_simple_cmd();
	redirect_index = find_redirection(token, i);
	if (redirect_index != -1)
		syntax_redirects(cmd_part, token, redirect_index);
}

void	syntax_simple_cmd()
{

}

void	syntax_redirects(char **cmd_part, int *token, int i)
{
	int	redirect_index;

	syntax_simple_redirect();
	redirect_index = find_redirection(token, i);
	if (redirect_index != -1)
		syntax_redirects(cmd_part, token,redirect_index);
}

void	syntax_simple_redirect()
{
	

}