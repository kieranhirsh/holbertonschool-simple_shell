#include "simple_shell.h"

/**
 * interactive_shell - interactive shell
 * @env: the environment
 *
 */
void interactive_shell(char **env)
{
	char *prompt;
	char **args, **path;
	int ii;

	while (1)	/* this loops infinitely until user exits the shell */
	{
		printf("$ ");	/* print prompt symbol */

		/* get the command from the user input */
		prompt = get_command();
		prompt = strtrim(prompt);
		if (prompt != NULL)				/* if prompt is not empty */
		{
			args = get_args(prompt);

			/* execute the command, checking for some built-in functions */
			if (strcmp(prompt, "exit") == 0)	/* if exit called */
			{	/* avoid memory leaks and exit the shell */
				free(prompt);
				free(args);
				exit(EXIT_SUCCESS);
			}
			else if (strcmp(prompt, "env") == 0)	/* in env called */
			{
				ii = 0;
				while (env[ii] != NULL)
				{
					printf("%s\n", env[ii]);
					ii += 1;
				}
			}
			else
			{
				path = get_path(env);
				execute_command(prompt, args, path, env);
				if (path != NULL)
				{
					free(path[0]);
					free(path);
				}
			}

			free(args);
		}
		else					/* if prompt is empty */
		{					/* do nothing */
		}

		free(prompt);

	}

}

