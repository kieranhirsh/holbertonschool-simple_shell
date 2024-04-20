#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid, parent_pid;

    my_pid = getpid();
    parent_pid = getppid();
    printf("my pid = %u\n", my_pid);
    printf("parent pid = %u\n", parent_pid);
    return (0);
}
