#include "simple_shell.h"

/**
 * interactive_shell - interactive shell
 * @env: the environment
 *
 */
void interactive_shell(char **env)
{
	char *prompt = NULL;
	char **args;
	dlistchar_t *path;

	path = get_path(env);

	while (1)	/* this loops infinitely until user exits the shell */
	{
		printf("$ ");	/* print prompt symbol */

		/* get the command from the user input */
		free(prompt);
		prompt = get_command();
		prompt = strtrim(prompt);
		args = get_args(prompt);

		/* execute the command, checking for some built-in functions */
		if (strcmp(prompt, "exit") == 0)	/* if exit called */
		{	/* avoid memory leaks and exit the shell */
			free(prompt);
			free(args);
			free_dlistchar(path);
			exit(EXIT_SUCCESS);
		}
		execute_command(prompt, args, path, env);

		free(args);

	}

}

