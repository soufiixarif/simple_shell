#include "shell.h"
/**
*is_built - handles in built shell commands
*@cmd: command
*Return: int
**/
int is_built(char *cmd)
{
	char *built[] = {
	"exit", "env", "setenv", "cd", NULL};
	int i = 0;

	while (built[i])
	{
		if (ft_strcmp(cmd, built[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
/**
*handelbuilt - handles inbuilt
*@com: command
*@av: arg vector
*@status: status
*@index: index
*Return: void
**/
void handelbuilt(char **com, char **av, int *status, int index)
{
	(void)av;
	(void)index;
	if (ft_strcmp(com[0], "exit") == 0)
		exit_sh(com, status, av, index);
	else if (ft_strcmp(com[0], "env") == 0)
		printf_env(com, status);

}
/**
*exit_sh - exits the shell
*@com: command
*@status: of the shell
*@av: arg vector
*@index: index
*Return: void
**/
void exit_sh(char **com, int *status, char **av, int index)
{
	int exval = (*status);
	char *idx, msg[] = ": exit: Illegal number: ";

	if (com[1])
	{
		if (intwithsign(com[1]))
		{
			exval = ft_atoi(com[1]);
		}
		else
		{
			idx = ft_itoa(index);
			write(STDERR_FILENO, av[0], ft_strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, ft_strlen(idx));
			write(STDERR_FILENO, msg, ft_strlen(msg));
			write(STDERR_FILENO, com[1], ft_strlen(com[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			freearr(com);
			*status = 2;
			return;
		}
	}
	freearr(com);
	exit(exval);
}
/**
*printf_env - prints the environment
*@com: command
*@status: status of the process
*Return: void
**/
void printf_env(char **com, int *status)
{
	int i = 0;
	(void)status;
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], ft_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	freearr(com);
	*status = 0;
}
