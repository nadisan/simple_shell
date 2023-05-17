#include "shell.h"

/**
  * exitShell - fun command exit to exit the shell
  * @args: user command
  * Return: 0 (exited shell successfully)
  */

int exitShell(char args[])
{
	if (_strcmp("exit", args[0]) == 0)
		return (0);
}
