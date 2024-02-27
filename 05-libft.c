#include "shell.h"
char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;
	int		len;

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
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
char *ft_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[i])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return(dest);
}

char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return(s1);
}
