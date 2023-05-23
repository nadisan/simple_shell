#include <unistd.h>

/**
 * _strlen - count number of charachter;
 * @c: The string to print
 *
 * Return: number of character.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _strlen(char *c)
{	int i = 0;

	while (c[i])
		i++;
	return (i);
}
