#include "simple_shell.h"


void free_path(char **path_array)
{
	int i = 0;

	if (path_array == NULL)
		return;

	while (path_array[i] != NULL)
	{
		free(path_array[i]);
		i++;
	}
	free(path_array);
}

void free_args(char **arg_list)
{
	int i;

	if (arg_list == NULL)
		return;

	for (i = 0; arg_list[i] != NULL; i++)
		free(arg_list[i]);

	free(arg_list);
}
