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
				write(1, argv[0], (sizeof(argv[0])));
				write(1, " : is a directory\n", 19);
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
  * @ac: (unused) number of arguments
  * @av: (unused) argument array
  * @env: environment variable
  * Return: 0 (program successful)
  */

int main(__attribute__((unused)) int ac,
		__attribute__((unused)) char **av, char **env)
{
	char *line = NULL;
	ssize_t input;
	size_t len = 0;
	char *argv[100];
	unsigned int i = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 5);
		input = getline(&line, &len, stdin);
		if (input == -1)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			break;
		}
		if (*line == '\n')
			continue;
		argv[0] = strtok(line, " \n");
		if (!argv[0])
			continue;
		while (argv[i])
		{	i++;
			argv[i] = strtok(NULL, " \n");
		}
		if (_strcmp("exit", argv[0]) == 0)
			break;
		check_cmd(argv, env);
		i = 0;
	}
	free(line);
	return (0);
}
