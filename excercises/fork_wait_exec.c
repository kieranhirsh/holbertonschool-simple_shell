#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int ii, status;
	pid_t pid, my_pid, parent_pid;

	my_pid = getpid();
	printf("I want to be a parent, my pid is %u\n", my_pid);
	for (ii = 0 ; ii < 5 ; ii++)
	{
		pid = fork();
		if (pid == 0)
		{
			my_pid = getpid();
			parent_pid = getppid();
			printf("I am a child, my pid is %u\n", my_pid);
			printf("my parent's pid is %u\n", parent_pid);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else if (pid < 0)
		{
		}
		else
		{
			wait(&status);
			printf("I am a proud parent, my pid is %u\n", my_pid);
		}
	}
	return (0);
}
