#include <stdio.h>
#include <unistd.h>

/**
 * p_pid - PID
 *
 * Return: Always 0.
 */
int p_pid(void)
{
	pid_t p_pid;
	p_pid = getppid();
	printf("%u\n", p_pid);
	return (0);
}
