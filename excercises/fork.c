#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t pid;
    int status;

    printf("Before fork\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }
    else if (pid == 0)
    {
    	printf("After fork\n");
    	my_pid = getpid();
    	printf("Child pid is %u\n", my_pid);
    }
    else
    {
	wait(&status);
    	printf("After fork\n");
    	my_pid = getpid();
    	printf("Parent pid is %u\n", my_pid);
    }
    return (0);
}
