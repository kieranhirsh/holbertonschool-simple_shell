#include <stdio.h>
#include <stdlib.h>

int _setenv(const char *name, const char *value, int overwrite);

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

	if (argc != 4)
	{
		printf("usage %s {variable_name} {value} {overwrite}\n", argv[0]);
		return (1);
	}

	printf("********** before calling _setenv **********\n");
	while (environ[ii] != 0)
	{
		printf("%s\n", environ[ii]);
		ii += 1;
	}
	printf("********************************************\n");

	_setenv(argv[1], argv[2], atoi(argv[3]));

	printf("********** after calling _setenv ***********\n");
	ii = 1;
	while (environ[ii] != 0)
	{
		printf("%s\n", environ[ii]);
		ii += 1;
	}
	printf("********************************************\n");

	return (0);

}

