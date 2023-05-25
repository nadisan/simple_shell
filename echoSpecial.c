#include "shell.h"

/**
  * echoSpecial - handle special xters
  * @comm: command
  * @a: param 2
  * Return: 1 or status
  */

int echoSpecial(char **comm, int a)
{
	char *path;
	unsigned int procId = getppid();

	if (_strncmp(comm[1], "$?", 2) == 0)
	{
		numPrint(a);
		_puts("\n");
	}
	else if (_strncmp(comm[1], "$$", 2) == 0)
	{
		unsignedPrint(procId);
		_puts("\n");
	}
	else if (_strncmp(comm[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		_puts(path);
		_puts("\n");
		free(path);
	}
	else
		return (printEcho(comm));

	return (1);
}
