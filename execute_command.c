#include "simple_shell.h"

/**
 * find_command - tries to find a command in the path
 * @command: the command
 * @path: the path
 *
 * Return: a pointer to a string containing the command to run, if found
 *         NULL, if not found
 */
char *find_command(char *command, dlistchar_t *path)
{
	int buffsize = 256;
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

	while (path != NULL)
	{
		sprintf(filepath, "%s/%s", path->str, command);

		if (stat(filepath, &st) == 0)
			return (filepath);

		path = path->next;
	}

	free(filepath);
	return (NULL);
}

/**
 * execute_command - executes a command
 * @command: the command
 * @args: the arguments
 * @path: the path
 *
 */
void execute_command(char *command, char **args, dlistchar_t *path)
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
			if (execvp(filepath, args) == -1)
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

