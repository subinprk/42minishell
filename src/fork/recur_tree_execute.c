/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_tree_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:53:44 by subpark           #+#    #+#             */
/*   Updated: 2023/12/20 06:58:30 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_simple_cmd(t_cmd *cmd, t_stdio *stdios, char **envp)
{
	static int		pipefd[2] = {-1, -1};
	static int		pipe_tmp[2];
	int				old_input;
	int				builtin;
	pid_t			pid;

	old_input = dup(pipe_tmp[0]);
	if (pipe(pipe_tmp) == -1)
		return (perror("Pipe: "));//exit with signals
	pid = fork();
	if (pid < 0)
		return (perror("Pipe: "));
	else if (pid == 0)
	{
		update_pipefd(&pipefd, cmd->pipe_exist, old_input, pipe_tmp[1]);
		update_redirfd(pipefd, stdios);//have to thing about 3d pointer
		builtin = check_builtin(cmd->left_child);
		if (builtin)
			builtin_action(cmd->right_child, cmd->right_child->cmdstr);
		else
		{
	 		print_error_cmd(cmd->left_child, envp);
			exec(cmd->right_child->cmdstr, envp);
		}
	}
	waitpid(pid, NULL, WNOHANG);
	free_stdios(stdios);
	stdios = NULL;
}

void	execute_simple_redirect(t_cmd *node, t_stdio **stdios)
{
	t_stdio	*redirection;
	t_stdio *curr;

	redirection = (t_stdio *)malloc(sizeof(t_stdio));
	if (*stdios == NULL)
	{
		redirection->filename = node->right_child->cmdstr[0];
		redirection->re_type = redirect_type(node->left_child);
		redirection->next_stdio = NULL;
		*stdios = redirection;
	}
	else
	{
		redirection->filename = node->right_child->cmdstr[0];
		redirection->re_type = redirect_type(node->left_child);
		redirection->next_stdio = NULL;
		curr = *stdios;
		while (curr->next_stdio)
			curr = curr->next_stdio;
		curr->next_stdio = redirection;
	}
}

void	execute_tree(t_cmd *node, t_stdio **stdios, char **envp)
{
	if (node->node_type == NODE_CMD || node->node_type == NODE_REDIRECTS)
		return ;
	else if (node->node_type == NODE_PIPE)
		;
	else if (node->node_type == NODE_SIMPLE_CMD)
		execute_simple_cmd(node, *stdios, envp);
	else if (node->node_type == NODE_SIMPLE_REDIRECT)
		execute_simple_redirect(node, stdios);
}

void	search_tree(t_cmd *node, char **envp)
{
	static t_stdio	*stdios;

	if (node == NULL)
		return ;
	execute_tree(node, &stdios, envp);
	if (node->left_child && (node->left_child->node_type != NODE_RED_TYPE ||
		node->left_child->node_type != NODE_FILE_PATH))
		search_tree(node->left_child, envp);
	if (node->right_child && (node->right_child->node_type != NODE_FILE_NAME ||
		node->right_child->node_type != NODE_ARGV))
		search_tree(node->right_child, envp);
}