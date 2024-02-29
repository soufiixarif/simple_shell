#include "shell.h"
/**
*ft_strdup - duplicates string
*@s1: string to usre
*Return: char
**/
char *ft_strdup(const char *s1)
{
	char	*p;
	int i;
	int len;

	p = NULL;

	i = -1;
	len = ft_strlen((char *)s1);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (++i < len && s1[i])
		*(p + i) = s1[i];
	*(p + i) = 0;
	return (p);
}
/**
*ft_strlen - string length
*@s: string
*Return: size_t
**/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/**
*ft_strcmp - compares string
*@s1: string 1
*@s2: string 1
*Return: int
**/
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/**
*ft_strcat - concatentates string
*@dest: destination
*@src: source
*Return: char
**/
char *ft_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
*ft_strcpy - copies a string
*@s1: string one
*@s2: string two
*Return: char
**/
char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
