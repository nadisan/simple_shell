#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
#include <sys/stat.h>

/**
  * cmdpath - finds file path of cmd and executes.
  * @env: enviroment variable
  * @argv: argument array for input
  * @av: argument array for running shell
  * Return: void
  */

void cmdpath(char **env, char **argv, char **av)
{	unsigned int i;
	char *path = NULL, *ele = NULL, *ch = "/", *str = NULL;
	struct stat st;
	char result[50];

	str = argv[0];
	i = 0;
	while (env[i] != NULL)
	{	path = _strdup(env[i]);
		if (_strcmp("PATH", strtok(path, "=")) == 0)
			break;
		i++;
		free(path);
	}
	path = realloc(path, _strlen(env[i]) + 1);
	path = strcpy(path, (env[i]));
	path[_strlen(env[i])] = '\0';
	strtok(path, "=");
	ele =  strtok(NULL, ":");
	while (ele)
	{
		_strcpy(result, ele);
		_strcat(result, ch);
		_strcat(result, str);
		if (stat(result, &st) == 0)
		{	argv[0] = result;
			_exec(argv);
			free(path);
			return;
		}
		i++;
		ele = strtok(NULL, ":");
	}
	_puts(av[0]);
	_puts(": ");
	_puts(argv[0]);
	_puts(": No such file or directory\n");
	free(path);
}
