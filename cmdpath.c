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
  * @argv: argument array
  * Return: void
  */

void cmdpath(char **env, char **argv)
{
	unsigned int i, j = 0;
	char *path, *ele, *ch = "/", *str = NULL;
	struct stat st;
	char result[100];

	str = argv[0];
	i = 0;
	while (env[i] != NULL)
	{	path = _strdup(env[i]);
		if (_strcmp("PATH", strtok(path, "=")) == 0)
			break;
		i++;
	}
	ele = malloc(sizeof(env[i]));
	ele =  strtok(NULL, ":");
	while (ele)
	{	_strcpy(result, ele);
		_strcat(result, ch);
		_strcat(result, str);
		if (stat(result, &st) == 0)
		{	argv[0] = result;
			_exec(argv);
			ele = '\0';
			return;
		}
		j++;
		ele = strtok(NULL, ":");
	}
	write(1, "./shell: ", 9);
	/*write(1, argv[0], (sizeof(argv[0]) - 1));*/
	write(1, "No such file or directory\n", 26);
}
