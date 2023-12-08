#include "../include/minishell.h"

void	print_2d_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
		printf("\t%s", str[i ++]);
}

void	print_every_node(t_cmd *tree, int i)
{
	if (tree->left_child != NULL)
		print_every_node(tree->left_child, i + 1);
	if (tree->right_child != NULL)
		print_every_node(tree->right_child, i + 1);
	printf("\n%d th depth node\n", i);
	printf("cmdstr:\n");
	print_2d_str(tree->cmdstr);
	printf("\nnode_type: %d\n", tree->node_type);
	printf("pipe_exist: %d\n", tree->pipe_exist);
	//printf("pre_flag: %d\n", tree->pre_flag);
}

void	print_single_node(t_cmd *tree)
{
	printf("cmdstr:\n");
	print_2d_str(tree->cmdstr);
	printf("\nnode_type: %d\n", tree->node_type);
	printf("pipe_exist: %d\n", tree->pipe_exist);
}