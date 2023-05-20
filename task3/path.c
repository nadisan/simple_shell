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
	char **ele = env;

        i = 0;
        while (env[i] != NULL)
        {
                if (strcmp("PATH", strtok(ele[i], "=")) == 0)
                        break;
                i++;
        }
	ele[j] = strtok(NULL, ":");
	while (ele[j])
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
    unsigned int i;
	 struct stat st;
	char **en = envi(env);
	  char *ch = "/ls";
	  char *str = NULL;
	
    i = 0;
     while(en[i])
    {
         str = realloc(str, sizeof(en[i]));
	strcpy(str, en[i]);
	strcat(str, ch);
	
        if (stat(str, &st) == 0)
        {
        	printf("%s ", str);
	   	printf(" FOUND\n");
		return (1);
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    
    return (0);
}
