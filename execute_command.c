#include "simple_shell.h"

/**
 * find_command - tries to find a command in the path
 * @command: the command
 * @path: the path
 *
 * Return: a pointer to a string containing the command to run, if found
 *         NULL, if not found
 */
char *find_command(char *command, char **path)
{
	int buffsize = 256, ii = 0;
	char *filepath = NULL;
	struct stat st;

	filepath = malloc(buffsize);
	if (filepath == NULL)
	{
		free(filepath);
		fprintf(stderr, "error in find_command: couldn't malloc filepath\n");
		exit(EXIT_FAILURE);
	}

	sprintf(filepath, "%s", command);

	if (stat(filepath, &st) == 0)
		return (filepath);

	if (path == NULL)
	{
		free(filepath);
		return (NULL);
	}

	while (path[ii] != NULL)
	{
		sprintf(filepath, "%s/%s", path[ii], command);

		if (stat(filepath, &st) == 0)
			return (filepath);

		ii += 1;
	}

	free(filepath);
	return (NULL);
}

/**
 * execute_command - executes a command
 * @command: the command
 * @args: the arguments
 * @path: the path
 * @env: the environment
 *
 */
void execute_command(char *command, char **args, char **path, char **env)
{
	char *filepath = NULL;
	int status;
	pid_t pid;

	filepath = find_command(command, path);

	if (filepath == NULL)
	{
		printf("%s: command not found\n", command);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(filepath, args, env) == -1)
			{
				fprintf(stderr, "error in execute_command: execve failed\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			fprintf(stderr, "error in execute_command: fork failed\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}

	free(filepath);

}

