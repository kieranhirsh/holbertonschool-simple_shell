#include "simple_shell.h"

/**
 * main - entry point
 *
 * Return: 0, success
 *
 */
int main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;

	/* determines if the file descriptor is associated with the terminal */
	if (isatty(STDIN_FILENO) == 1)
		interactive_shell(env);
	else
		noninteractive_shell(env);

	return (0);
}
