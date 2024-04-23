#include "simple_shell.h"

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
	int lenpath, status;
	int lencommand = 0;
	struct stat st;
	pid_t pid;

	while (command[lencommand] != '\0')
	{
		lencommand += 1;
		if (command[lencommand] == '\n')
			command[lencommand] = '\0';
	}

	filepath = malloc(sizeof(char) * (lencommand + 1));
	sprintf(filepath, "%s", command);

	while ((stat(filepath, &st) != 0) && (path != NULL))
	{
		lenpath = 0;
		while (path->str[lenpath] != '\0')
			lenpath += 1;

		free(filepath);
		filepath = malloc(sizeof(char) * (lenpath + lencommand + 2));
		if (filepath == NULL)
		{
			free(filepath);
			perror("error in execute_command: could not malloc filepath correctly");
			exit(-1);
		}
		sprintf(filepath, "%s/%s", path->str, command);

		path = path->next;

	}

	if (stat(filepath, &st) != 0)
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
				perror("error in execute_command: child process cannot execute command\n");
			}
		}
		else if (pid < 0)
		{
			perror("error in execute_command: fork failed\n");
		}
		else
		{
			wait(&status);
		}
	}

	free(filepath);

}

