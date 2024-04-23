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
	int lencommand = 0;
	int lenpath;
	char *filepath = NULL;
	struct stat st;

	while (command[lencommand] != '\0')
	{
		lencommand += 1;
		if (command[lencommand] == '\n')
			command[lencommand] = '\0';
	}
	filepath = malloc(sizeof(char) * (lencommand + 1));
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
		lenpath = 0;
		while (path->str[lenpath] != '\0')
			lenpath += 1;
		free(filepath);
		filepath = realloc(filepath, sizeof(char) * (lenpath + lencommand + 2));
		if (filepath == NULL)
		{
			free(filepath);
			fprintf(stderr, "error in find_command: couldn't realloc filepath\n");
			exit(EXIT_FAILURE);
		}
		sprintf(filepath, "%s/%s", path->str, command);
		if (stat(filepath, &st) == 0)
			return (filepath);
		path = path->next;
	}
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
	extern char **environ;
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
			if (execve(filepath, args, environ) == -1)
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

