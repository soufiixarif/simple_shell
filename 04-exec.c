#include "shell.h"
/**
*
*
*
**/
int ft_execute(char **com, char **av, int index)
{
    pid_t child;
    int status;
    char *cmd;

    cmd = getlinepath(com[0]);
    if (!cmd)
    {
        errormsg(av[0], com[0], index);
        free(cmd);
        freearr(com);
        return (127);
    }
    child = fork();
    if (child == 0)
    {
        if (execve(com[0],com,environ) == -1)
        {
            free(cmd), cmd = NULL;
            freearr(com);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freearr(com);
        free(cmd), cmd = NULL;

    }
    return (WEXITSTATUS(status));
}
