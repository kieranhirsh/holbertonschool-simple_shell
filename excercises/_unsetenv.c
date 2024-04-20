#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _unsetenv - unsets an environment variable
 * @name: the name of the environment variable to be unset
 *
 * Return: 0, on success
 *         -1, on failure
 */
int _unsetenv(const char *name)
{
	extern char **environ;
	int ii = 0;
	int jj;

	while (environ[ii] != NULL)
	{
		jj = 0;

		while ((name[jj] == environ[ii][jj]) && (name[jj] != NULL))
			jj += 1;

		if (name[jj] == NULL)
		{
			while (environ[ii + 1] != NULL)
			{
				environ[ii] = environ[ii + 1];
				ii += 1;
			}
			environ[ii] = NULL;

			return (0);
		}

		ii += 1;
	}

	return (1);

}

