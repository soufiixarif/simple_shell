#include "shell.h"
int main(int ac, char **av)
{
    char *line = NULL;
    char **com = NULL;
    int status = 0;
    (void) ac;

    while(1)
    {
        line = ft_getline();
        if (!line) // reach end of file ctr + D
        {
            if (isatty(STDERR_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return(status);
        }
        com = split(line);
        if (!com)
            continue;
        status = ft_execute(com,av);

    }
}
