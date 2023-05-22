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
int _exec(char **argv);
void cmdpath(char **env, char **argv);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *src);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
