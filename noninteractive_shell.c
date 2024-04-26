#include "simple_shell.h"

/**
 * noninteractive_shell - noninteractive shell
 * @env: the environment
 *
 */
void noninteractive_shell(char **env)
{
	char *prompt;
	char **args, **path;

	while (1)	/* this loops infinitely until user exits the shell */
	{
		/* get the command from the user input */
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

		free(prompt);
		free(args);

	}

}

