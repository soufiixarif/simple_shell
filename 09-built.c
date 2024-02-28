#include "shell.h"
int is_built(char *cmd)
{
    char *built[] = {
        "exit", "env", "setenv", "cd", NULL
    };
    int i = 0;
    while(built[i])
    {
        if (ft_strcmp(cmd,built[i]) == 0)
            return(i);
    } 
    return (0);
}

void handelbuilt(char **com, char **av, int status, int index)
{
    (void)av;
    (void)index;
    if (ft_strcmp(com[0],"exit") == 0)
        exit_sh(com,status);
    else if (ft_strcmp(com[0],"env") == 0)
        printf_env(com,status);
}
void exit_sh(char **com, int status)
{
    freearr(com);
    exit(status);
}
void printf_env(char **com,int status)
{
    int i = 0;
    (void)status;
    while (environ[i])
    {
        write(STDOUT_FILENO,environ[i],strlen(environ[i]));
        write(STDOUT_FILENO,"\n",1);
    }
    freearr(com);
}
