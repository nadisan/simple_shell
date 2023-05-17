#include "shell.h"

/**
  * _strcmp - fun compare two strings
  * @s1: string one
  * @s2: string two
  * Return: 0 (similar) or (s1 - s2)
  */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
