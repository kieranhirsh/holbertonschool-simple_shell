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

	if (getline(&line, &buffersize, stdin) == -1)	/* if getline fails */
	{						/* avoid memory leaks, and exit with failure */
		if (feof(stdin))			/* if end of file is reached */
		{					/* feof function might not be allowed by checker*/
			free(line);
			exit(EXIT_SUCCESS);
		}
		else					/* if getline failed for other reasons */
		{
			free(line);
			fprintf(stderr, "error in get_command: getline failed\n");
			exit(EXIT_FAILURE);
		}
	}

	return (line); /* otherwise return the command line prompt */

}
