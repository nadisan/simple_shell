#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char **envi(char **env)
{
        unsigned int i, j = 0;
	char *path;
	char **ele;

        i = 0;
        while (env[i] != NULL)
        {
		path = strdup(env[i]);
                if (strcmp("PATH", strtok(path, "=")) == 0)
                        break;
                i++;
		path = NULL;
        }
	ele = malloc(sizeof(env[i]));
	ele[j] = strtok(NULL, ":");
	printf("%s\n", ele[j]);
	while(ele[j])
	{
		j++;
		ele[j] = strtok(NULL, ":");
	}
        return (ele);
}
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
unsigned int i = 0;
struct stat st;
char **en = envi(env);
char *ch = "/ls";
char *str = NULL;

	while(en[i])
	{
	str = realloc(str, sizeof(en[i]));
	strcpy(str, en[i]);
	strcat(str, ch);
	if (stat(str, &st) == 0)
	{
		printf("%s ", str);
		return (1);
        }
        i++;
	str = NULL;
    }
  
    return (i);
}
