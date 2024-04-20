#include <stdio.h>
#include <stdlib.h>

int _unsetenv(const char *name);

/**
 * main - calls _setenv
 *
 * Return: 0, on success
 *         1, on failure
 *
 */
int main(int argc, char **argv)
{
	extern char **environ;
	int ii = 0;

	if (argc != 2)
	{
		printf("usage %s {variable_name}\n", argv[0]);
		return (1);
	}

	printf("********** before calling _unsetenv **********\n");
	while (environ[ii] != 0)
	{
		printf("%s\n", environ[ii]);
		ii += 1;
	}
	printf("**********************************************\n");

	_unsetenv(argv[1]);

	printf("********** after calling _unsetenv ***********\n");
	ii = 1;
	while (environ[ii] != 0)
	{
		printf("%s\n", environ[ii]);
		ii += 1;
	}
	printf("**********************************************\n");

	return (0);

}

