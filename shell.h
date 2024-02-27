#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
extern char **env;


char *ft_getline(void);
char **split(char *line);
int ft_execute(char ** com, char **av);
void freearr(char **arr);

//libft Functions
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void freearr(char **arr);



#endif
