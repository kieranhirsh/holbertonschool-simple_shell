#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *_getenv(const char *name);

/**
 * main - prints $PATH, one directory at a time
 *
 * Return: 0, on success
 *         1, on failure
 *
 */
int main(int argc, char **argv)
{
	char *path, *directory, *filepath;
	int ii, lenfile, lendir;
	struct stat sb;

	if (argc < 2)
	{
		printf("usage %s {prognames}\n", argv[0]);
		return (1);
	}

	for (ii = 1 ; ii < argc ; ii++)
	{
		lenfile = 0;
		while (argv[ii][lenfile] != NULL)
			lenfile += 1;

		path = _getenv("PATH");
		directory = strtok(path, ":");

		do {
			lendir = 0;
			while (directory[lendir] != 0)
				lendir += 1;

        		filepath = malloc(sizeof(char) * (lenfile + lendir + 2));
			if (filepath == -1)
			{
				free(filepath);
				return (-1);
			}

        		sprintf(filepath, "%s/%s", directory, argv[ii]);

			if (stat(filepath, &sb) == 0)
			{
				printf("%s\n", filepath);
				break;
			}
		} while ((directory = strtok(NULL, ":")) != NULL);
	}

	return (0);

}
