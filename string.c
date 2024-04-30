#include "simple_shell.h"

/**
 * strtrim - trims leading and trailing whitespaces
 * @str: te strim to trim
 *
 * Return: a pointer to the trimmed string
 *
 */
char *strtrim(char *str)
{
	char *temp;
	int ii = 0, jj = 0, buffsize = 256;

	if (str == NULL)
	{
		return (NULL);
	}

	temp = malloc(sizeof(char) * buffsize);
	if (temp == NULL)	/* if malloc failed */
	{			/* avoid memory leaks and exit with failure*/
		free(temp);
		fprintf(stderr, "error in strtrim: couldn't malloc temp\n");
		exit(EXIT_FAILURE);
	}

	/* find the first non-whitespace character of str */
	while ((*(str + ii) == ' ') || (*(str + ii) == '\n') || (*(str + ii) == '\t'))
		ii += 1;

	/* find the length of str */
	while (str[jj] != '\0')
		jj += 1;

	/* find the last non-whitespace character of str */
	/* and replace the next character with NULL */
	while ((str[jj - 1] == ' ') || (str[jj - 1] == '\n') || (str[jj - 1] == '\t'))
	{
		jj -= 1;
	}
	str[jj] = '\0';

	strcpy(temp, str + ii);
	free(str);

	return (temp);
}

