#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i ++]);
	free(arr);
}

int	array_length_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i ++;
	return (i);
}

char	**cpy_full_2d_array(char **origin)
{
	int		i;
	int		origin_length;
	char	**array;

	origin_length = array_length_2d(origin);
	array = (char **)malloc(sizeof(char *) * ((origin_length) + 1));
	i = 0;
	while(i < origin_length)
	{
		array[i] = strdup(origin[i]);
		if (!array[i])
			return (NULL);
		i ++;
	}
	printf("copy length: %d\n", origin_length);
	array[origin_length] = NULL;
	return (array);
}

int main()
{
	char **strs;
	char **cpys;
	int	i;

	strs = (char **)malloc(sizeof(char *) * 3);
	strs[0] = strdup("Hello");
	strs[1] = strdup("World");
	strs[2] = NULL;

	cpys = cpy_full_2d_array(strs);
	i = 0;
	while (cpys[i])
	{
		printf("%s\n", cpys[i]);
		i ++;
	}
	free_2d(strs);
	free_2d(cpys);
}
