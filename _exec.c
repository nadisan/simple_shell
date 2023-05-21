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

        pid = fork();

        if (pid == -1)
        {       perror("fork");
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
