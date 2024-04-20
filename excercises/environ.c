#include <stdio.h>

/**
 * main - environ example
 *
 * Return: Always 0.
 */
int main(void)
{
	extern char **environ;
	int ii = 0;

	while (environ[ii] != NULL)
	{
		printf("%s\n", environ[ii]);
		ii += 1;
	}

}

