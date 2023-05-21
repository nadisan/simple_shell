#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
#include <sys/stat.h>

/**
  * envi - executes cmd if it's in path
  * @argv: argument array
  * Return: 0 (program successful)
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
	{	path = strdup(env[i]);
		if (_strcmp("PATH", strtok(path, "=")) == 0)
			break;
		i++;
	}
	ele = malloc(sizeof(env[i]));
	ele =  strtok(NULL, ":");
	while (ele)
	{	strcpy(result, ele);
		strcat(result, ch);
		strcat(result, str);
		if (stat(result, &st) == 0)
		{	argv[0] = result;
			break;
		}
		j++;
		ele = strtok(NULL, ":");
	}
	_exec(argv);
	ele = '\0';
}
