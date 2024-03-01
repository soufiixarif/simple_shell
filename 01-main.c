#include "shell.h"
/**
*main - shell's main.c
*@ac: argument count
*@av : argument vector
*Return: int
**/
int main(int ac, char **av)
{
	char *line = NULL;
	char **com = NULL;
	int status = 0, index = 0;
	(void) ac;

	while (1)
	{
		line = ft_getline();
		if (!line)
		{
			if (isatty(STDERR_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		index++;
		com = split(line);
		if (!com)
			continue;
		if (is_built(com[0]))
		{
			handelbuilt(com,av,&status,index);
		}
		else
			status = ft_execute(com, av, index);
	}
}
