#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
#include <sys/stat.h>


/**
 * sig - prevents ctrl c termination
 * @sig_num: signal input
 * Return: void
 */

void sig(int sig_num)
{
	if (sig_num == SIGINT)
		_putstr("\n($) ");
}

/**
  * check_cmd - check access of cmd
  * @argv: argument array from input
  * @av: argument array for runing shell
  * @env: array of enviroment
  * Return: 0 (program successful)
  */

void check_cmd(char **argv, char **av, char **env)
{
	struct stat fs;

	if (access(argv[0], F_OK) == 0)
	{
		if (stat(argv[0], &fs) != -1)
		{
			if (fs.st_mode == 16877)
			{
				_putstr(av[0]);
				 _putstr(": ");
				_putstr(argv[0]);
				_putstr(": is a directory\n");
			}
			else
				_exec(argv);
		}
	}
	else
		cmdpath(env, argv, av);
}

/**
  * main - simple_shell program
  * @ac: (unused) number of arguments
  * @av: argument array
  * @env: environment variable
  * Return: 0 (program successful)
  */

int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *line = NULL;
	ssize_t input;
	size_t len = 0;
	char *argv[100];
	unsigned int i = 0;

	signal(SIGINT, sig);
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
		check_cmd(argv, av, env);
		i = 0;
	}
	free(line);
	return (0);
}
