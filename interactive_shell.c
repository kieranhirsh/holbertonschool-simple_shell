#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"

/**
 * interactive_shell - interactive shell
 *
 */
void interactive_shell(void)
{
	char *prompt = NULL;
	char **args;
	int ii;

	do {
		printf("What is thy bidding, master?$ ");
		prompt = get_command();
		args = get_args(prompt);
		printf("You have chosen: %s", prompt);

		ii = 0;
		if (args[ii] != NULL)
		{
			printf("\nYou are very argumentative\n");
			while (args[ii] != NULL)
			{
				printf("argument #%i: %s\n", ii, args[ii]);
				ii += 1;
			}
		}

		free(args);

	} while (strcmp(prompt, "exit\n") != 0);
}

