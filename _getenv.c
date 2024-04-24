#include "simple_shell.h"

/**
 * _getenv - returns an environment variable
 * @name: the desired environment variable
 * @env: the environment
 *
 * Return: the environment variable
 */
char *_getenv(const char *name, char **env)
{
	int ii = 0;
	int jj;

	while (env[ii] != NULL)
	{
		jj = 0;

		while ((name[jj] == env[ii][jj]) && (name[jj] != '\0'))
			jj += 1;

		if (name[jj] == '\0')
		{
			return (env[ii] + jj + 1);
		}

		ii += 1;
	}

	return (NULL);

}

