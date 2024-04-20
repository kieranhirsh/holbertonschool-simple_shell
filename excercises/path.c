#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);

/**
 * main - prints $PATH, one directory at a time
 *
 * Return: always 0
 *
 */
int main()
{
	char *path, *directory;

	path = _getenv("PATH");
	directory = strtok(path, ":");
	printf("%s\n", directory);

	while ((directory = strtok(NULL, ":")) != NULL)
		printf("%s\n", directory);

	return (0);

}

