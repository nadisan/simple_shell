#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include <sys/stat.h>
extern char **environ;

int _putchar(char c);
int _strcmp(char *s1, char *s2);
void printEnv(void);
int _exec(char **argv);
void cmdpath(char **env, char **argv);

#endif
