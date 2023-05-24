#include "shell.h"

/**
 * _getline - gets string line from stdin file
 *
 * Return: Read string with null pointer
 */

char *_getline()
{
	char *buffer = NULL, *buff;
	int i = 0, x = 0, buffersize = BUFSIZE;
	char c = 0, prebuf = '\0';

	buffer = malloc(BUFSIZE);
	if (!buffer)
		return (NULL);
	for (; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		x = read(STDIN_FILENO, &c, 1);
		if (x == 0)
		{	free(buffer);
			exit(EXIT_SUCCESS);
		}
		if ((c == ' ' && i == 0) || (c == ' ' && prebuf == ' '))
			i--;
		else
		{	buffer[i] = c;
			if (i >= buffersize)
			{
				buffer = realloc(buffer, (BUFSIZE + 2));
				if (!buffer)
				{	free(buffer);
					return (NULL);
				}
			}
			prebuf = buffer[i];
		}
	}
	buffer[i] = '\0';

	hashtag(buffer);
	buff = buffer;
	return (buff);
}

/**
 * hashtag - checks for # comments
 * @buff: string to check
 * Return: void
 */

void hashtag(char *buff)
{
	int i = 0;

	if (buff[0] == '#')
		buff[i] = '\0';
	i++;
	while (buff[i])
	{
		if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
			buff[i] = '\0';
		i++;
	}
}

