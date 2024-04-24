#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"

/**
 * get_command - reads the command line prompt
 *
 * Return: a pointer to the char storing the command line prompt
 *
 */
char *get_command(void)
{
	char *line = NULL;
	size_t buffersize = 0;
	ssize_t charsread;

	charsread = getline(&line, &buffersize, stdin);

	if (charsread < 0)				/* if getline fails */
	{
		if (charsread == EOF)			/* if end of file is reached */
		{					/* avoid memory leaks and exit with success */
			free(line);
			exit(EXIT_SUCCESS);
		}
		else					/* if getline failed for other reasons */
		{					/* avoid memory leaks and exit with failure */
			free(line);
			fprintf(stderr, "error in get_command: getline failed\n");
			exit(EXIT_FAILURE);
		}
	}

	return (line);					/* on success, return the command line prompt */

}
