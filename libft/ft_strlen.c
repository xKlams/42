#include "libft.h"

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[++i])
		i++;
	return (i);
}
