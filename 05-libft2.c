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
    return(c);
}
char    *ft_itoa(int nbr)
{
    int len = nbrlen(nbr);
    char *s;
    int i;
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
