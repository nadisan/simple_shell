#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
#include <sys/stat.h>


char **envi(char **env)
{
        unsigned int i, j = 0;
        char **ele = env;

        i = 0;
        while (env[i] != NULL)
        {
                if (strcmp("PATH", strtok(ele[i], "=")) == 0)
                        break;
                i++;
        }
        ele[j] = strtok(NULL, ":");
        while (ele[j])
                {
                        j++;
                        ele[j] = strtok(NULL, ":");
                }
        return (ele);
}

char **check( char **argv, char **env)
{
	char **en = envi(env);
        char *str = NULL;
	unsigned int j;
	struct stat fs;

	while(en[j])
        {
		str = realloc(str, sizeof(en[j]));
		strcpy(str, en[j]);
		strcat(str, "/");
		strcat(str, argv[0]);
		
		if (stat(str, &fs) == 0)
		{
			strcpy(argv[0], str);
			return(argv);
		}
		j++;
	}
	return (argv);
}

/**
  * _exec - executes command
  * @argv: command line and arguments
  * Return: 0 (program successful)
  */

int _exec(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
    		
	if (pid == -1)
	{	perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	return (0);
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
	unsigned int i = 0, j = 0;
	struct stat fs;
	char **en = envi(env);
        char *str = NULL;

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
		if (_strcmp("exit", argv[0]) == 0)
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
		{	  while(en[j])
        	{
                	str = realloc(str, sizeof(en[j]));
                	strcpy(str, en[j]);
               		 strcat(str, "/");
          	      strcat(str, argv[0]);

                	if (stat(str, &fs) == 0)
                {
                        strcpy(argv[0], str);
                        _exec(argv);
                }
                	j++;
        	}
		}
		free(argv);
	}
	return (0);
}
