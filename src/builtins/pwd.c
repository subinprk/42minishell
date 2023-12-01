/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:35:29 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/01 13:29:55 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*retrieves and prints the current working directory. It uses the getcwd
function to obtain the path, then prints tp the standard output.
Then frees the memory in getcwd. */
void   	our_pwd(void)
{
	char	*current_directory;
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	current_directory = getcwd(0, 1024);
	ft_putendl_fd(current_directory, 1);
	free(current_directory);
	g_exit_status = 0;
}