#include "simple_shell.h"

/**
 * read_line_from_stdin - reads a line from stdin until a
 * newline or EOF
 *
 * Description: Allocates a buffer to read characters from
 * stdin until it encounters a newline ('\n') or EOF. The
 * newline character is replaced by a null terminator.
 * The buffer is resized if needed. On memory failure,
 * prints an error and exits.
 *
 * Return: Returns the buffer containing the line on success.
 * Exits with `EXIT_SUCCESS` on EOF, and with `EXIT_FAILURE`
 * on memory allocation failure.
 */

char *read_line_from_stdin(void)
{
	size_t bufsize = 1024, position = 0;
	char *buffer = malloc(bufsize);
	char *new_buffer;
	int ch;

	if (buffer == NULL)
	{
		fprintf(stderr, "Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		buffer[position++] = (char) ch;
		if (position == bufsize)
		{
			bufsize *= 2;
			new_buffer = realloc(buffer, bufsize);

			if (new_buffer == NULL)
			{
				free(buffer);
				fprintf(stderr, "Failed to reallocate memory\n");
				exit(EXIT_FAILURE);
			}
			buffer = new_buffer;
		}
	}
	free(buffer);
	exit(EXIT_SUCCESS);
}
