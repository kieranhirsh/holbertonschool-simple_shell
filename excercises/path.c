#include <stdio.h>
#include <string.h>
#include "path.h"

/**
 * main - prints $PATH, one directory at a time
 *
 * Return: always 0
 *
 */
int main()
{
	char *path, *directory;
	dlistchar_t *head;

	head = NULL;
	
	path = _getenv("PATH");
	directory = strtok(path, ":");
	add_dnodechar_end(&head, directory);

	while ((directory = strtok(NULL, ":")) != NULL)
		add_dnodechar_end(&head, directory);

	print_dlistchar(head);
	free_dlistchar(head);

	return (0);

}

