#include <stdio.h>
#include <string.h>
#include "simple_shell.h"

/**
 * interactive_shell - interactive shell
 *
 */
void interactive_shell(void)
{
	char *prompt = NULL;

	do {
		printf("What is thy bidding, master?$ ");
		prompt = get_command();
		printf("You have chosen: %s", prompt);

	} while (strcmp(prompt, "exit\n") != 0);

}
