#include "shell.h"
/**
*freearr - frees array
*@arr: array in question
*Return: void
**/
void freearr(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i])
		free(arr[i]), arr[i++] = NULL;
	free(arr), arr = NULL;
}
/**
*errormsg - error message
*@sh: sh
*@cmd: command
*@index: index
*Return: void
**/
void errormsg(char *sh, char *cmd, int index)
{
	char *i, msg[] = ": not found\n";

	i = ft_itoa(index);
	write(STDERR_FILENO, sh, ft_strlen(sh));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, ft_strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, msg, ft_strlen(msg));
	free(i);

}
/**
*intwithsign -unsigned digits
*@s: unsigned digit
*Return: int
**/
int intwithsign(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

