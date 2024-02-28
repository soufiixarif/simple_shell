#include "shell.h"
char *getlinepath(char *linecommande)
{
    char *path, *full_cmd, *fold;
    struct stat st;
    int i = 0;

    while (linecommande[i])
    {
        if (linecommande[i] == '/')
        {
            if(stat(linecommande,&st) == 0)
                return(ft_strdup(linecommande));
            return (NULL);
        }
        i++;
    }
    path = f_getenv("PATH");
    if (!path)
        return (NULL);
    fold = strtok(path, ":");
    while (fold)
    {
        full_cmd = malloc(ft_strlen(fold) + ft_strlen (linecommande) + 2);
        if (full_cmd)
        {
            ft_strcpy(full_cmd,fold);
            ft_strcat(full_cmd, "/");
            ft_strcat(full_cmd,linecommande);
            if (stat(full_cmd, &st) == 0)
                return (free(path),path = NULL,full_cmd);
            free (full_cmd),full_cmd = NULL;
            fold = strtok(NULL,":");
        }
    }
    free(path);
    return(NULL);
}
