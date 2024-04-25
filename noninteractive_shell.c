#include "simple_shell.h"

/**
 * noninteractive_shell - non-interactive shell
 * @env: the environment
 *
 */
void noninteractive_shell(char **env)
{
	char *prompt = NULL;
	char **args;
	char **path;

	path = get_path(env);

	do {
		free(prompt);
		prompt = get_command();
		prompt = strtrim(prompt);
		if (strcmp(prompt, "") != 0)	/* if prompt is not empty */
		{
			args = get_args(prompt);
			execute_command(prompt, args, path, env);
		}

		free(args);

	} while (strcmp(prompt, "exit") != 0);

	free(prompt);
	free(path);
	exit(EXIT_SUCCESS);

}
