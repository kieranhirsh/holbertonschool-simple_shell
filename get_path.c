#include <stdio.h>
#include <string.h>
#include "simple_shell.h"

/**
 * main - gets the path
 *
 * Return: a pointer to the path
 *
 */
dlistchar_t *get_path(void)
{
	char *path, *directory;
	dlistchar_t *head;

	head = NULL;
	
	path = _getenv("PATH");
	directory = strtok(path, ":");
	add_dnodechar_end(&head, directory);

	while ((directory = strtok(NULL, ":")) != NULL)
		add_dnodechar_end(&head, directory);

	return (head);

}

