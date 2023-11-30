/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:09:26 by subpark           #+#    #+#             */
/*   Updated: 2023/11/30 15:15:05 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heredoc_input(int filefd, char *word)
{
	char	*line;

	line = readline("heredoc> ");
	while (ft_strcmp(line, word) != 0)
	{
		write(filefd, line, ft_strlen(line));
		write(filefd, "\n", 1);
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
}