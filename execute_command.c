#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
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
	int lenpath;
	int lencommand = 0;
	struct stat st;

	while (command[lencommand] != NULL)
	{
		lencommand += 1;
		if (command[lencommand] == '\n')
			command[lencommand] = NULL;
	}

	do {
		lenpath = 0;
		while (path->str[lenpath] != NULL)
			lenpath += 1;

		free(filepath);
		filepath = malloc(sizeof(char) * (lenpath + lencommand + 2));
		if (filepath == -1)
		{
			free(filepath);
			perror("error in execute_command: could not malloc filepath correctly");
			exit(-1);
		}
		sprintf(filepath, "%s/%s", path->str, command);

		printf("path->str = %s:\n", path->str);
		printf("filepath = %s:\n", filepath);
		printf("stat = %i:\n", stat(filepath, &st));
		path = path->next;

	} while ((stat(filepath, &st) != 0) && (path != NULL));

	if (path == NULL)
		printf("%s: command not found\n", filepath);
	else
		printf("%s: command found\n", filepath);



	free(filepath);

}
