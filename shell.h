#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int _putchar(char c);
int _strcmp(char *s1, char *s2);
void printEnv(void);
int _fork(void);
int _pid(void);
int p_pid(void);
int prompt(void);
int _wait(void);
int eg_exec(void);

#endif
