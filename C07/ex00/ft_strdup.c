#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
#include<stdio.h>

char	*ft_strcpy(char *str, char *cpy)
{
	int i;

	i = 0;
	while(str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	return(cpy);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	
	copy = (char *)(malloc(ft_strlen(str) + 1));
	copy = ft_strcpy(str, copy);
	copy[ft_strlen(str)] = 0;
	return(copy);
}
