#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _setenv - sets an environment variable
 * @name: the name of the environment variable to be changed
 * @value: the value that the environment variable is to be changed to
 * @overwrite: 0, if value is not to be overwritten
 *             non-zero, otherwise
 *
 * Return: 0, on success
 *         -1, on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char *newvar;
	int ii = 0, lenname = 0, lenvalue = 0;
	int jj;

	while (name[lenname] != NULL)
		lenname += 1;
	while (value[lenvalue] != NULL)
		lenvalue += 1;

	newvar = malloc(sizeof(char) * (lenname + lenvalue + 2));
	if (newvar == -1)
	{
		free(newvar);
		return (-1);
	}

	sprintf(newvar, "%s=%s", name, value);

	while (environ[ii] != NULL)
	{
		jj = 0;

		while ((name[jj] == environ[ii][jj]) && (name[jj] != NULL))
			jj += 1;

		if (name[jj] == NULL)
		{
			if (overwrite == 0)
				return (0);

			environ[ii] = newvar;
			return (0);
		}

		ii += 1;
	}

	environ[ii] = newvar;
	environ[ii + 1] = NULL;

	return (0);

}

