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
	char *delimiter = " ";	/* !! this may edits to allow for more delimiters !! */
	int ii = 0;
	int jj;

	arg_list = malloc(sizeof(char *));
	if (arg_list == NULL)			/* if malloc fails */
	{					/* avoid memory leaks, and exit with failure */
		free(arg_list);
		fprintf(stderr, "error in get_args: couldn't malloc arg_list\n");
		exit(EXIT_FAILURE);
	}
	arg = strtok(prompt, delimiter);

	do {					/* loop through the prompt until the end is reached */
		jj = 0;
		while (arg[jj] != '\0')		/* step through current argument */
		{				/* avoid memory leaks, and exit with failure */
			jj += 1;
			if (arg[jj] == '\n')	/* if string ends with a newline */
				arg[jj] = '\0';	/*replace it with a NULL character */
		}

		arg_list = realloc(arg_list, sizeof(char *) * (ii + 2));
		if (arg_list == NULL)		/* if realloc fails */
		{
			free(arg_list);
			fprintf(stderr, "error in get_args: couldn't realloc arg_list\n");
			exit(EXIT_FAILURE);
		}
		arg_list[ii] = arg;

		ii += 1;
	} while ((arg = strtok(NULL, delimiter)) != NULL);

	arg_list[ii] = NULL;
	free(arg);

	return (arg_list);
}

