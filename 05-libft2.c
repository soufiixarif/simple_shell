#include "shell.h"
/**
*nbrlen - number length
*@n: integer
*Return: int
**/
static int nbrlen(int n)
{
	int c = 0;

	if (n < 0)
	{
		c++;
		n *= -1;
	}
	while (n > 10)
	{
		n /= 10;
		c++;
	}
	return (c);
}
/**
*ft_itoa - integer to ascii
*@nbr: number
*Return: char
**/
char *ft_itoa(int nbr)
{
	int len = nbrlen(nbr);
	char *s;
	int i;

	s = NULL;
	len += 1;
	s = malloc(len);
	i = 0;
	if (nbr == 0)
		s[0] = '0';
	if (nbr < 0)
	{
		s[i] = '-';
		nbr *= -1;
	}
	s[len] = '\0';
	len--;
	while (nbr > 0)
	{
		s[len] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		len--;
	}
	return (s);
}
/**
 *ft_atoi - ascii to int
 *@str: string
 *Return: int
 **/
int ft_atoi(const char *str)
{
	int i = 0;
	int s = 1;
	int r = 0;

	while (str[i] == 32 || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + str[i] - 48;
		i++;
	}
	return (r * s);
}
