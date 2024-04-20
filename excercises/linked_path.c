#include <stdio.h>
#include <stdlib.h>
#include "path.h"

/**
 * add_dnodechar_end - adds a node to the end of a list
 * @head: a pointer to the start of the list
 * @str: the string to add to the list
 *
 * Return: if success, a pointer to new element
 *         otherwise, NULL
 *
 */
dlistchar_t *add_dnodechar_end(dlistchar_t **head, char *str)
{
	dlistchar_t *new;
	dlistchar_t *temp;

	new = malloc(sizeof(dlistchar_t));
	if (new == NULL)
		return (NULL);

	new->str = str;
	new->next = NULL;
	

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		temp = *head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new;
		new->prev = temp;
	}

	return (new);
}

/**
 * print_dlistchar - prints a singly linked list
 * @head: the list
 *
 */
void print_dlistchar(const dlistchar_t *head)
{
	while (head != NULL)
	{
		printf("%s\n", head->str);

		head = head->next;
	}

}

/**
 * free_dlistchar - frees a list
 * @head: the list
 *
 */
void free_dlistchar(dlistchar_t *head)
{
	if (head->next != NULL)
		free_dlistchar(head->next);

	free(head);

}

