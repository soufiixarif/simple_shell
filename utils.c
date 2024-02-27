#include "shell.h"
void freearr(char **arr)
{
    int i = 0;
    if (!arr)
        return ;
    while(arr[i])
        free(arr[i]),arr[i++] = NULL;
    free(arr), arr = NULL;
}
