#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"

/**
 * get_args - converts a command line prompt into individual arguments
 *
 * Return: a pointer to the char storing the arguments
 *
 */
char **get_args(char *prompt)
{
	char **arg_list;
	char *arg;
	char *delimiter = " ";
	int ii = 0;
	int jj;

	arg_list = malloc(sizeof(char *));
	arg = strtok(prompt, delimiter);

	while ((arg = strtok(NULL, delimiter)) != NULL)
	{
		jj = 0;
		while (arg[jj] != NULL)
		{
			jj += 1;
			if (arg[jj] == '\n')
				arg[jj] = NULL;
		}

		arg_list = realloc(arg_list, (ii + 2) * sizeof(char *));
		arg_list[ii] = arg;

		ii += 1;
	}

	arg_list[ii] = NULL;
	free(arg);

	return (arg_list);

}
