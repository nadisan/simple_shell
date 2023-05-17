#include "shell.h"
#include <unistd.h>

/**
  * printEnv - fun print all environment variables
  * Return: void
  */

void printEnv(void)
{
	int e = 0, i = 0;

	while (environ[e])
	{
		i = 0;
		while (environ[e][i])
		{
			_putchar(environ[e][i]);
			i++;
		}

		if (i != 0)
			_putchar('\n');
		e++;
	}
}
