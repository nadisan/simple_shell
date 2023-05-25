#include "shell.h"

/**
   * _getenv - fun get environment
   * @param: args
   * Return: vl or NULL
   */

char *_getenv(char *param)
{
	size_t nlen, vlen;
	char *v;
	int i, g, h;

	nlen = _strlen(param);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(param, environ[i], nlen) == 0)
		{
			vlen = _strlen(environ[i]) - nlen;
			v = malloc(sizeof(char) * vlen);
			if (!v)
			{
				free(v);
				perror("Malloc unsuccessful");
				return (NULL);
			}

			g = 0;
			for (h = nlen + 1; environ[i][h]; h++, g++)
			{
				v[g] = environ[i][h];
			}
			v[g] = '\0';

			return (v);
		}
	}

	return (NULL);
}
