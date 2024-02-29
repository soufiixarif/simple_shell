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

extern char **environ;


char *ft_getline(void);
char **split(char *line);
int ft_execute(char ** com, char **av, int index);
void freearr(char **arr);
char *f_getenv(char *var);
char *getlinepath(char *linecommande);
void errormsg(char *sh, char *cmd, int index);
int is_built(char *cmd);
void handelbuilt(char **com, char **av, int status, int index);
void exit_sh(char **com, int status);
void printf_env(char **com,int status);


//libft Functions
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void freearr(char **arr);
int ft_strcmp(char *s1, char *s2);
char *ft_strcat(char *dest, char *src);
char *ft_strcpy(char *s1, char *s2);
char    *ft_itoa(int nbr);



#endif
