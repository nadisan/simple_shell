#INclude <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void printEnv(char **envObj)
{
    int e = 0, i = 0;

    while (envObj[e])
    {
        i = 0;
        while (envObj[e][i])
        {
            putchar(envObj[e][i]);
            i++;
        }

        if (i != 0)
            putchar('\n');
        e++;
    }
}

int main(void)
{
    char *shellSymbol = ">_ ";
    char *userInput = NULL;    
    size_t userInputSize = 0;
    char *pathTols = "/bin/ls";
    char *argv[] = {"ls", "-l", NULL};
    int execReturn;
    char *token1;
    char *delim = " \n";
    pid_t procId;

    printf("%s", shellSymbol);
    
    if (getline(&userInput, &userInputSize, stdin) == -1) 
    {
        perror("Getline failed!");
        free(userInput);
    }

    token1 = strtok(userInput, delim);
    if (token1 != NULL && *token1 != '\n' && (strcmp(token1, "ls") == 0 || strcmp(token1, "/bin/ls") == 0))
    {
        procId = fork();
        if (procId == 0)
        {
            execReturn = execve(pathTols, argv, NULL);
            if (execReturn == -1)
                perror("Execve error!");
        }
        else if (procId > 0)
        {
            wait(NULL);
            printf("✅ Child process complete! ls / bin/ls done!\n");
        }
        else if (procId == -1)
            perror("Error: Forking failed");
    }
    else if (token1 != NULL && *token1 != '\n' && (strcmp(token1, "env") == 0 || strcmp(token1, "printenv") == 0))
    {
        procId = fork();
        if (procId == 0)
            printEnv(environ);
        else if (procId > 0)
        {
            wait(NULL);
            printf("✅ Child process complete: environment variables printed\n");
        }
        else if (procId == -1)
            perror("Error: Forking failed!");
    }
     else if (token != NULL && *token != '\n' && (strcmp(token, "exit") == 0))
    {
        printf("Exiting....\n");
        return (0);
    }
    printf("<<<<< 💯 At the end of parent process, exiting 💯 >>>>>\n");

    free(userInput);
    return (0);
}
