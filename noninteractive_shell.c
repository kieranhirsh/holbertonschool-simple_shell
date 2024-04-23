#include "simple_shell.h"

/**
 * noninteractive_shell - non-interactive shell
 *
 */
void noninteractive_shell(void)
{
	char *prompt = NULL;
	char **args;
	dlistchar_t *path;

	path = get_path();

	do {
		free(prompt);
		prompt = get_command();
		args = get_args(prompt);
		execute_command(prompt, args, path);

		free(args);

	} while (strcmp(prompt, "exit") != 0);

	free(prompt);
	free_dlistchar(path);
	exit(1);

}
