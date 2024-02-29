#include "shell.h"
/**
*
*
*
*
**/
void freearr(char **arr)
{
    int i = 0;
    if (!arr)
        return ;
    while(arr[i])
        free(arr[i]),arr[i++] = NULL;
    free(arr), arr = NULL;
}
void errormsg(char *sh, char *cmd, int index)
{
    char *i,msg[] = ": not found\n";

    i = ft_itoa(index);
    write(STDERR_FILENO, sh, ft_strlen(sh));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, i, ft_strlen(i));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, ft_strlen(cmd));
    write(STDERR_FILENO, msg, ft_strlen(msg));
    free(i);

}
