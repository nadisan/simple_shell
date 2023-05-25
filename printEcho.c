#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
  * printEcho - fun print echo command
  * @param: args
  * Return: 1 or -1
  */

int printEcho(char **param)
{
	pid_t procId;
	int d;

	procId = fork();
	if (procId == 0)
	{
		if (execve("/bin/echo", param, environ) == -1)
			return (-1);
		exit(EXIT_FAILURE);
	}
	else if (procId < 0)
		return (-1);
	do {
		waitpid(procId, &d, WUNTRACED);
	} while (!WIFEXITED(d) && !WIFSIGNALED(d));

	return (1);
}
