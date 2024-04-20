#ifndef PATH
#define PATH

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

char *_getenv(const char *name);
dlistchar_t *add_dnodechar_end(dlistchar_t **head, char *str);
void print_dlistchar(const dlistchar_t *head);
void free_dlistchar(dlistchar_t *head);

#endif 
