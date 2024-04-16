#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"

/**
 * get_args - reads the command line prompt
 *
 * Return: a pointer to the char storing the command line prompt
 *
 */
char *get_command(void)
{
	char *line = NULL;
	size_t buffersize = 0;

	if (getline(&line, &buffersize, stdin) == -1) /* if getline fails */
	{
		/* avoid memory leaks, and exit with failure */
		free(line);
		exit(EXIT_FAILURE);
	}

	return (line);

}
