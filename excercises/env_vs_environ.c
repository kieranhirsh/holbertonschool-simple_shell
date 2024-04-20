#include <stdio.h>

/**
 * main - environ example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("address of env = %p\naddress of environ = %p\n", &*env, &*environ);

	return (0);

}

