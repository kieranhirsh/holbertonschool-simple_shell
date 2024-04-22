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
	dlistchar_t *path;

	path = get_path();

	do {
		printf("$ ");

		free(prompt);
		prompt = get_command();
		args = get_args(prompt);
		execute_command(prompt, args, path);

		free(args);

	} while (strcmp(prompt, "exit") != 0);

	free(prompt);
	free_dlistchar(path);

}

