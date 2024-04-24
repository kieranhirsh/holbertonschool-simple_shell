#include "simple_shell.h"

/**
 * get_path - gets the path
 * @env: the environment
 *
 * Return: a pointer to the path
 *
 */
dlistchar_t *get_path(char **env)
{
	char *path, *directory;
	dlistchar_t *head;

	head = NULL;

	path = _getenv("PATH", env);
	directory = strtok(path, ":");
	add_dnodechar_end(&head, directory);

	while ((directory = strtok(NULL, ":")) != NULL)
		add_dnodechar_end(&head, directory);

	return (head);

}

