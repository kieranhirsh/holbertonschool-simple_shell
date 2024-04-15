#include <unistd.h>
#include "simple_shell.h"

/**
 * main - entry point
 *
 * Return: 0, success
 *
 */
int main(void)
{
	/* determines if the file descriptor is associated with the terminal */
	if (isatty(STDIN_FILENO) == 1)
		interactive_shell();
	else
		noninteractive_shell();

	return (0);
}
