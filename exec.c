#include <stdio.h>
#include <unistd.h>


/**
 * eg_exec- execve example
 *
 * Return: Always 0.
 */
int eg_exec(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
