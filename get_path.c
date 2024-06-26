#include "simple_shell.h"

/**
 * get_path - gets the path
 * @env: the environment
 *
 * Return: a pointer to the path
 *
 */
char **get_path(char **env)
{
	char *path, *directory, *temp;
	char **path_array;
	int buffsize = 256, ii = 0;

	path_array = malloc(sizeof(char *) * buffsize);
	temp = malloc(sizeof(char) * buffsize);

	path = _getenv("PATH", env);
	if (path == NULL)
	{
		free(path_array);
		free(temp);
		return (NULL);
	}

	strcpy(temp, path);
	directory = strtok(temp, ":");
	path_array[ii] = directory;

	while ((directory = strtok(NULL, ":")) != NULL)
	{
		ii += 1;
		path_array[ii] = directory;
	}
	path_array[ii + 1] = '\0';

	return (path_array);

}

