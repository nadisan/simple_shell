#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
#include <sys/stat.h>

void envi(char **env, char **argv)
{
        unsigned int i, j = 0;
	char *path;
	char *ele;
	struct stat st;
char result[100];	
char *str;
char *ch = "/";

str = argv[0];

        i = 0;
        while (env[i] != NULL)
        {
		path = strdup(env[i]);
	
                if (strcmp("PATH", strtok(path, "=")) == 0)
                        break;
                i++;
        }
	ele = malloc(sizeof(env[i]));
	ele =  strtok(NULL, ":");
	while(ele)
	{
		strcpy(result, ele);
		strcat(result, ch);
		strcat(result, str);
		
		if (stat(result, &st) == 0)
		{
			argv[0] = result;
			break;
       		}
	       
		j++;
		ele = strtok(NULL, ":");
	}
	_exec(argv);
	printf("%s", argv[0]);
	printf("%s", argv[1]);
}


/**
  * main - simple_shell program
  * Return: 0 (program successful)
  */

int main(int ac, char **av, char **env)
{
	char *buffer = "($) ";
	ssize_t input;
	char *line = NULL;
	size_t len = 0;
	char **argv;
	unsigned int i = 0;
	struct stat fs;

	while (1)
	{
		write(STDOUT_FILENO, buffer, 5);
		input = getline(&line, &len, stdin);
		if (input == -1)
		{	write(1, "\n", 1);
			free(line);
			break;
		}
		if (*line == '\n')
			continue;
		argv = malloc(sizeof(char) * input);
		argv[0] = strtok(line, " \n");
		if (argv == NULL)
			return (0);
		while (argv[i])
		{	i++;
			argv[i] = strtok(NULL, " \n");
		}
		if (strcmp("exit", argv[0]) == 0)
		{	free(line);
			free(argv);
			break;
		}
		if (access(argv[0],F_OK) == 0)
		{	 if(stat(argv[0],&fs) != -1)
		
             			{	if (fs.st_mode == 16877)
                                	{        write(1, "bash :", 7);
						 write(1, argv[0], sizeof(argv[0]));
						write(1, " : is a directory\n", 20);
                                	}
					else
						_exec(argv);
				}
		}
		else 
			envi(env, argv);
		free(argv);
	}
	return (0);
}
