#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"


/**
  * _exec - executes command
  * @argv: command line and arguments
  * Return: 0 (program successful)
  */

int _exec(char **argv)
{
	pid_t pid;
	int status;
	char **envp;

	envp = NULL;
	pid = fork();
	if (pid == -1)
	{	perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{	execve(argv[0], argv, envp);
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

int main(void)
{
	char *buffer = "($) ";
	ssize_t input;
	char *line = NULL;
	size_t len = 0;
	char **argv;
	int i = 0;

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
		_exec(argv);
		i = 0;
		free(argv);
	}
	return (0);
}
