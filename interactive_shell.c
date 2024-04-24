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

	do {
		printf("$ ");

		free(prompt);
		prompt = get_command();
		args = get_args(prompt);
		execute_command(prompt, args, path, env);

		free(args);

	} while (strcmp(prompt, "exit") != 0);

	free(prompt);
	free_dlistchar(path);
	exit(EXIT_SUCCESS);

}

