#include <stddef.h>

/**
 * _getenv - returns an environment variable
 * @name: the desired environment variable
 *
 * Return: the environment variable
 */
char *_getenv(const char *name)
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
			return (environ[ii] + jj + 1);
		}

		ii += 1;
	}

	return (NULL);

}

