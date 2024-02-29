#include "shell.h"
/**
*split - tokenize input
*@line: address of memory to tokenize
*Return: char
**/
char **split(char *line)
{
	char *token = NULL;
	char **com = NULL;
	char *tmp;
	char *sep;
	int c = 0;
	int i = 0;

	tmp = ft_strdup(line);
	sep = " \t\n";
	token = strtok(tmp, sep);
	if (!token)
		return (free(line), free(tmp), NULL);

	while (token)
	{
		c++;
		token = strtok(NULL, sep);
	}
	free(tmp);
	com = malloc(sizeof(char *) * (c + 1));
	if (!com)
		return (free(line), line = NULL, NULL);
	token = strtok(line, sep);

	while (token)
	{
		com[i] = ft_strdup(token);
		token = strtok(NULL, sep);
		i++;
	}
	com[i] = NULL;
	free(line);
	return (com);
}
