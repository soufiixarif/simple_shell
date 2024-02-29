#include "shell.h"
/**
*f_getenv - get environment
*@var: variable
*Return: char
**/
char *f_getenv(char *var)
{
	char *key = NULL, *ptr = NULL, *val = NULL, *tmp = NULL;
	int i = 0;

	while (environ[i])
	{
		ptr = ft_strdup(environ[i]);
		key = strtok(ptr, "=");
		if (ft_strcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			tmp = ft_strdup(val);
			free(ptr);
			return (tmp);
		}
		else
			free(tmp);
		i++;
	}
	return (NULL);
}
