#include "shell.h"
int ft_execute(char ** com, char **av)
{
    pid_t child;
    int status;
    char **env;

    child = fork();
    if (child == 0)
    {
        if (execve(com[0],com,env) == -1)
        {
            perror(av[0]);
            freearr(com);
            exit(127);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freearr(com);
    }
    return (WEXITSTATUS(status));
}
