#include "simple_shell.h"

/**
 * noninteractive_shell - non-interactive shell
 * @env: the environment
 *
 */
void noninteractive_shell(char **env)
{
	char *prompt = NULL;
	char **args, **path;

	do {
		free(prompt);
		prompt = get_command();
		prompt = strtrim(prompt);
		if (strcmp(prompt, "") != 0)		/* if prompt is not empty */
		{
			args = get_args(prompt);

			/* execute the command, checking for some built-in functions */
			if (strcmp(prompt, "exit") == 0)	/* if exit called */
			{	/* avoid memory leaks and exit the shell */
				free(prompt);
				free(args);
				free(path);
				exit(EXIT_SUCCESS);
			}
			else
			{
				path = get_path(env);
				execute_command(prompt, args, path, env);
				free(path[0]);
				free(path);
			}
		}
		else					/* if prompt is empty */
		{					/* do nothing */
		}

		free(args);

	} while (strcmp(prompt, "exit") != 0);

	free(prompt);
	free(path);
	exit(EXIT_SUCCESS);

}
