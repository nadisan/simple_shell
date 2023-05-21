#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
#include <sys/stat.h>

/**
  * check_cmd - check access of cmd
  * @argv: argument array
  * @env: array of enviroment
  * Return: 0 (program successful)
  */

void check_cmd(char **argv, char **env)
{
	struct stat fs;

	if (access(argv[0], F_OK) == 0)
	{
		if (stat(argv[0], &fs) != -1)
		{
			if (fs.st_mode == 16877)
			{
				write(1, "bash :", 7);
				write(1, argv[0], sizeof(argv[0]));
				write(1, " : is a directory\n", 20);
			}
			else
				_exec(argv);
		}
	}
	else
		cmdpath(env, argv);
}


/**
  * main - simple_shell program
  * @ac: number of arguments
  * @av: argument array
  * @env: environment variable
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
		{	write(1, "\n\n", 3);
			write(1, "[Disconnected...]\n", 20);
			free(line);
			free(argv);
			break;
		}
		check_cmd(argv, env);
		free(argv);
		i = 0;
	}
	return (0);
}
