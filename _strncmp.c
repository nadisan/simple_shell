#include "shell.h"

/**
  * _strncmp - fun compare
  * @s1: str1
  * @s2: str2
  * @l: xters number
  * Return: 0 or -1
  */

int _strncmp(const char *s1, const char *s2, size_t l)
{
	size_t x;

	if (s1 == NULL)
		return (-1);

	for (x = 0; x < l && s2[x]; x++)
	{
		if (s1[x] != s2[x])
			return (1);
	}
	return (0);
}
