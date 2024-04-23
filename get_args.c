#include "simple_shell.h"

/**
 * get_args - converts a command line prompt into individual arguments
 * @prompt: the command line prompt
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
	if (arg_list == NULL)
	{
		fprintf(stderr, "error in get_args: couldn't malloc arg_list\n");
		exit(EXIT_FAILURE);
	}
	arg = strtok(prompt, delimiter);

	do {
		jj = 0;
		while (arg[jj] != '\0')
		{
			jj += 1;
			if (arg[jj] == '\n')
				arg[jj] = '\0';
		}

		arg_list = realloc(arg_list, sizeof(char *) * (ii + 2));
		arg_list[ii] = arg;

		ii += 1;

	} while ((arg = strtok(NULL, delimiter)) != NULL);

	arg_list[ii] = NULL;
	free(arg);

	return (arg_list);

}

