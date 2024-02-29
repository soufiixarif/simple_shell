#include "shell.h"
/**
*
*
*
**/
char *f_getenv(char *var)
{
    char *key, *ptr, *val, *tmp = NULL;
    int i = 0;

    while (environ[i])
    {
        ptr = ft_strdup(environ[i]);
        key = strtok(ptr, "=");
        if (ft_strcmp(key, var) == 0)
        {
            val = strtok(NULL,"\n");
            tmp = ft_strdup(val);
            free(ptr);
            return (tmp);
        }
        else 
            free (tmp), tmp = NULL;
        i++;
    }
    return (NULL);
}
