#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
char *envp (int ac, char **av, char **env)
{
	unsigned int i, j = 0;
	char **ele = NULL;
	
	i = 0;
	while (env[i] != NULL)
	{
		if (strcmp("PATH", strtok(env[i], "=")) == 0)
			break;
		i++;
	}
	ele = realloc(ele,sizeof(env[i]));
	ele[j] =  strtok(NULL, ":");
	printf("%s\n", ele[j]);
	j++;
	ele[j] =  strtok(NULL, ":");
	 printf("%s\n", ele[j]);
	 ele[j] =  strtok(NULL, ":");
	 printf("%s\n", ele[j]);
	 ele[j] =  strtok(NULL, ":");
         printf("%s\n", ele[j]);
	 ele[j] =  strtok(NULL, ":");
         printf("%s\n", ele[j]);
	 ele[j] =  strtok(NULL, ":");
         printf("%s\n", ele[j]);

	return (ele[j]);
}
