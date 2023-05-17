#ifndef SHELL_H
#define DHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int _putchar(char c);
void printEnv(void);

#endif
