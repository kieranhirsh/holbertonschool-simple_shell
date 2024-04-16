#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

void interactive_shell(void);
void noninteractive_shell(void);
char *get_command(void);
char **get_args(char *prompt);

#endif
