#include <stdio.h>

char *_getenv(const char *name);

/**
 * main - calls _getenv
 *
 * Return: always 0
 *
 */
int main(int argc, char **argv)
{
	int ii;

	for (ii = 1 ; ii < argc ; ii++)
		printf("%s = %s\n\n", argv[ii], _getenv(argv[ii]));

	return (0);

}

