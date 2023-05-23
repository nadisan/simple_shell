#include "shell.h"

/**
 *_strdup - copies string data into new memory
 *@src: src memory to copy from
 *Return: pointer to created memory
 */

char *_strdup(char *src)
{
	int i = 0;
	char *p;

	while (src[i])
	{
		i++;
	}
	p = malloc(sizeof(char) * i);
	if (!p)
	{
		free(p);
		return (NULL);
	}
	_memcpy(p, src, i);
	return (p);
}

/**
 * _memcpy - a function that copies memory of str and returns memory
 * @dest: memory where is stored
 * @src: src memory toi copy from
 * @n: number of char bytes
 * Return: new memory destination pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
	}
	return (dest);
}
