#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"

char *line = NULL;

/**
 * handle_sigint_command - frees the memory whent the process is killed
 * @signum: the kill signal
 *
 */
void handle_sigint_command(int signum)
{
	if (signum > 0)
		free(line);

	exit(EXIT_SUCCESS);
}

/**
 * get_command - reads the command line prompt
 *
 * Return: a pointer to the char storing the command line prompt
 *
 */
char *get_command(void)
{
	size_t buffersize = 0;
	ssize_t charsread;

	signal(SIGINT, handle_sigint_command);

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
