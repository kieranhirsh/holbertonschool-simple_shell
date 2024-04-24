#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * struct dlistchar_s - doubly linked list
 * @str: string
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 *
 */
typedef struct dlistchar_s
{
	char *str;
	struct dlistchar_s *prev;
	struct dlistchar_s *next;
} dlistchar_t;

void interactive_shell(char **env);
void noninteractive_shell(char **env);
char *get_command(void);
char *strtrim(char *str);
char **get_args(char *prompt);
void execute_command(char *prompt, char **args, dlistchar_t *path, char **env);
dlistchar_t *get_path(char **env);
char *_getenv(const char *name, char **env);
dlistchar_t *add_dnodechar_end(dlistchar_t **head, char *str);
void free_dlistchar(dlistchar_t *head);
char *read_line_from_stdin(void);

#endif
